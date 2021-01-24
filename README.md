
<!-- README.md is generated from README.Rmd. Please edit that file -->

# wk

<!-- badges: start -->

[![Lifecycle:
experimental](https://img.shields.io/badge/lifecycle-experimental-orange.svg)](https://www.tidyverse.org/lifecycle/#experimental)
[![R build
status](https://github.com/paleolimbot/wk/workflows/R-CMD-check/badge.svg)](https://github.com/paleolimbot/wk/actions)
[![Codecov test
coverage](https://codecov.io/gh/paleolimbot/wk/branch/master/graph/badge.svg)](https://codecov.io/gh/paleolimbot/wk?branch=master)
<!-- badges: end -->

The goal of wk is to provide lightweight R, C, and C++ infrastructure
for a distributed ecosystem of packages that operate on collections of
coordinates. First, wk provides vector classes for points, segments,
circles, rectangles, well-known text (WKT), and well-known binary (WKB).
Second, wk provides a C API and set of S3 generics (`wk_handle()` and
`wk_translate()`) for event-based iteration over vectors of geometries
that allows clear separation code and distribution of responsibility
among multiple packages.

## Installation

You can install the released version of wk from
[CRAN](https://cran.r-project.org/) with:

``` r
install.packages("wk")
```

You can install the development version from
[GitHub](https://github.com/) with:

``` r
# install.packages("remotes")
remotes::install_github("paleolimbot/wk")
```

If you can load the package, you’re good to go\!

``` r
library(wk)
```

## Vector classes

Use `wkt()` to mark a character vector as containing well-known text, or
`wkb()` to mark a vector as well-known binary. Use `xy()`, `xyz()`,
`xym()`, and `xyzm()` to create vectors of points, and `rct()` to create
vectors of rectangles. These classes have full
[vctrs](https://vctrs.r-lib.org) support and `plot()`/`format()` methods
to make them as frictionless as possible working in R and RStudio.

``` r
wkt("POINT (30 10)")
#> <wk_wkt[1]>
#> [1] POINT (30 10)
as_wkb(wkt("POINT (30 10)"))
#> <wk_wkb[1]>
#> [1] <POINT (30 10)>
xy(1, 2)
#> <wk_xy[1]>
#> [1] (1 2)
rct(1, 2, 3, 4)
#> <wk_rct[1]>
#> [1] [1 2 3 4]
```

## Generics

The wk package is made up of readers, handlers, and filters. Readers
parse the various formats supported by the wk package, handlers
calculate values based on information from the readers (e.g.,
translating a vector of geometries into another format), and filters
transform information from the readers (e.g., transforming coordinates)
on the fly. The `wk_handle()` and `wk_translate()` generics power
operations for many geometry vector formats without having to explicitly
support each one.

## C API

The distributed nature of the wk framework is powered by a [\~100-line
header](https://github.com/paleolimbot/wk/blob/master/inst/include/wk-v1.h)
describing the types of information that parsers typically encounter
when reading geometries and the order in which that information is
typically organized. Detailed information is available in the [C and C++
API
article](https://paleolimbot.github.io/wk/dev/articles/articles/philosophy.html).

``` r
wk_debug(
  as_wkt("LINESTRING (1 1, 2 2, 3 3)"),
  wkt_format_handler(max_coords = 2)
)
#> initialize (dirty = 0  -> 1)
#> vector_start: <Unknown type / 0>[1] <0x7ffeecb08058> => WK_CONTINUE
#>   feature_start (1): <0x7ffeecb08058>  => WK_CONTINUE
#>     geometry_start (<none>): LINESTRING <0x7ffeecb07ec8> => WK_CONTINUE
#>       coord (1): <0x7ffeecb07ec8> (1.000000 1.000000)  => WK_CONTINUE
#>       coord (2): <0x7ffeecb07ec8> (2.000000 2.000000)  => WK_ABORT_FEATURE
#> vector_end: <0x7ffeecb08058>
#> deinitialize
#> [1] "LINESTRING (1 1, 2 2..."
```

## sf support

The wk package implements a reader and writer for sfc objects so you can
use them wherever you’d use an `xy()`, `rct()`, `crc()`, `seg()`,
`wkb()`, or `wkt()`:

``` r
wk_debug(
  sf::st_sfc(sf::st_linestring(rbind(c(1, 1), c(2, 2), c(3, 3)))),
  wkt_format_handler(max_coords = 2)
)
#> initialize (dirty = 0  -> 1)
#> vector_start: <Unknown type / 0>[1] <0x7ffeecb0b298> => WK_CONTINUE
#>   feature_start (1): <0x7ffeecb0b298>  => WK_CONTINUE
#>     geometry_start (<none>): LINESTRING[3] <0x7ffeecb0b210> => WK_CONTINUE
#>       coord (1): <0x7ffeecb0b210> (1.000000 1.000000)  => WK_CONTINUE
#>       coord (2): <0x7ffeecb0b210> (2.000000 2.000000)  => WK_ABORT_FEATURE
#> vector_end: <0x7ffeecb0b298>
#> deinitialize
#> [1] "LINESTRING (1 1, 2 2..."
```

## Lightweight

The wk package has one recursive dependency
([cpp11](https://cpp11.r-lib.org)), compiles in \~10 seconds, and runs
all 600 expectations in \~4 seconds. The package can read and write WKB
at approximately the same speed as the sf package.

``` r
nc <- sf::read_sf(system.file("shape/nc.shp", package = "sf"))$geometry
nc_wkb <- as_wkb(nc)

bench::mark(
  wk_handle(nc, wkb_writer()),
  unclass(sf::st_as_binary(nc))
)
#> # A tibble: 2 x 6
#>   expression                         min   median `itr/sec` mem_alloc `gc/sec`
#>   <bch:expr>                    <bch:tm> <bch:tm>     <dbl> <bch:byt>    <dbl>
#> 1 wk_handle(nc, wkb_writer())     89.2µs    120µs     6676.      47KB     6.95
#> 2 unclass(sf::st_as_binary(nc))  332.4µs    389µs     2023.      52KB     4.19

bench::mark(
  wk_handle(nc_wkb, sfc_writer()),
  sf::st_as_sfc(structure(nc_wkb, class = "WKB"))
)
#> # A tibble: 2 x 6
#>   expression                                        min median `itr/sec`
#>   <bch:expr>                                      <bch> <bch:>     <dbl>
#> 1 wk_handle(nc_wkb, sfc_writer())                 251µs  290µs     2981.
#> 2 sf::st_as_sfc(structure(nc_wkb, class = "WKB")) 744µs  873µs      984.
#> # … with 2 more variables: mem_alloc <bch:byt>, `gc/sec` <dbl>
```

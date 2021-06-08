// Generated by cpp11: do not edit by hand
// clang-format off


#include "cpp11/declarations.hpp"

// handle-wkt.cpp
cpp11::sexp wk_cpp_handle_wkt(cpp11::strings wkt, cpp11::sexp xptr, bool reveal_size);
extern "C" SEXP _wk_wk_cpp_handle_wkt(SEXP wkt, SEXP xptr, SEXP reveal_size) {
  BEGIN_CPP11
    return cpp11::as_sexp(wk_cpp_handle_wkt(cpp11::as_cpp<cpp11::decay_t<cpp11::strings>>(wkt), cpp11::as_cpp<cpp11::decay_t<cpp11::sexp>>(xptr), cpp11::as_cpp<cpp11::decay_t<bool>>(reveal_size)));
  END_CPP11
}
// wkt-writer.cpp
cpp11::sexp wk_cpp_wkt_writer(int precision, bool trim);
extern "C" SEXP _wk_wk_cpp_wkt_writer(SEXP precision, SEXP trim) {
  BEGIN_CPP11
    return cpp11::as_sexp(wk_cpp_wkt_writer(cpp11::as_cpp<cpp11::decay_t<int>>(precision), cpp11::as_cpp<cpp11::decay_t<bool>>(trim)));
  END_CPP11
}
// wkt-writer.cpp
cpp11::sexp wk_cpp_wkt_formatter(int precision, bool trim, int max_coords);
extern "C" SEXP _wk_wk_cpp_wkt_formatter(SEXP precision, SEXP trim, SEXP max_coords) {
  BEGIN_CPP11
    return cpp11::as_sexp(wk_cpp_wkt_formatter(cpp11::as_cpp<cpp11::decay_t<int>>(precision), cpp11::as_cpp<cpp11::decay_t<bool>>(trim), cpp11::as_cpp<cpp11::decay_t<int>>(max_coords)));
  END_CPP11
}

extern "C" {
/* .Call calls */
extern SEXP _wk_wk_cpp_handle_wkt(SEXP, SEXP, SEXP);
extern SEXP _wk_wk_cpp_wkt_formatter(SEXP, SEXP, SEXP);
extern SEXP _wk_wk_cpp_wkt_writer(SEXP, SEXP);
extern SEXP wk_c_bbox_handler_new();
extern SEXP wk_c_count_handler_new();
extern SEXP wk_c_debug_filter_new(SEXP);
extern SEXP wk_c_handler_addr(SEXP);
extern SEXP wk_c_handler_void_new();
extern SEXP wk_c_identity_filter_new(SEXP);
extern SEXP wk_c_meta_handler_new();
extern SEXP wk_c_problems_handler_new();
extern SEXP wk_c_read_crc(SEXP, SEXP, SEXP);
extern SEXP wk_c_read_rct(SEXP, SEXP);
extern SEXP wk_c_read_sfc(SEXP, SEXP);
extern SEXP wk_c_read_wkb(SEXP, SEXP);
extern SEXP wk_c_read_xy(SEXP, SEXP);
extern SEXP wk_c_sfc_writer_new();
extern SEXP wk_c_vector_meta_handler_new();
extern SEXP wk_c_vertex_filter_new(SEXP, SEXP);
extern SEXP wk_c_wkb_writer_new(SEXP, SEXP);
extern SEXP wk_c_xy_writer_new();

static const R_CallMethodDef CallEntries[] = {
    {"_wk_wk_cpp_handle_wkt",        (DL_FUNC) &_wk_wk_cpp_handle_wkt,        3},
    {"_wk_wk_cpp_wkt_formatter",     (DL_FUNC) &_wk_wk_cpp_wkt_formatter,     3},
    {"_wk_wk_cpp_wkt_writer",        (DL_FUNC) &_wk_wk_cpp_wkt_writer,        2},
    {"wk_c_bbox_handler_new",        (DL_FUNC) &wk_c_bbox_handler_new,        0},
    {"wk_c_count_handler_new",       (DL_FUNC) &wk_c_count_handler_new,       0},
    {"wk_c_debug_filter_new",        (DL_FUNC) &wk_c_debug_filter_new,        1},
    {"wk_c_handler_addr",            (DL_FUNC) &wk_c_handler_addr,            1},
    {"wk_c_handler_void_new",        (DL_FUNC) &wk_c_handler_void_new,        0},
    {"wk_c_identity_filter_new",     (DL_FUNC) &wk_c_identity_filter_new,     1},
    {"wk_c_meta_handler_new",        (DL_FUNC) &wk_c_meta_handler_new,        0},
    {"wk_c_problems_handler_new",    (DL_FUNC) &wk_c_problems_handler_new,    0},
    {"wk_c_read_crc",                (DL_FUNC) &wk_c_read_crc,                3},
    {"wk_c_read_rct",                (DL_FUNC) &wk_c_read_rct,                2},
    {"wk_c_read_sfc",                (DL_FUNC) &wk_c_read_sfc,                2},
    {"wk_c_read_wkb",                (DL_FUNC) &wk_c_read_wkb,                2},
    {"wk_c_read_xy",                 (DL_FUNC) &wk_c_read_xy,                 2},
    {"wk_c_sfc_writer_new",          (DL_FUNC) &wk_c_sfc_writer_new,          0},
    {"wk_c_vector_meta_handler_new", (DL_FUNC) &wk_c_vector_meta_handler_new, 0},
    {"wk_c_vertex_filter_new",       (DL_FUNC) &wk_c_vertex_filter_new,       2},
    {"wk_c_wkb_writer_new",          (DL_FUNC) &wk_c_wkb_writer_new,          2},
    {"wk_c_xy_writer_new",           (DL_FUNC) &wk_c_xy_writer_new,           0},
    {NULL, NULL, 0}
};
}

extern "C" void R_init_wk(DllInfo* dll){
  R_registerRoutines(dll, NULL, CallEntries, NULL, NULL);
  R_useDynamicSymbols(dll, FALSE);
  R_forceSymbols(dll, TRUE);
}

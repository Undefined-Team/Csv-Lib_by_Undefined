#ifndef UD_CSV_H
# define UD_CSV_H

// Lib
#include <ud_string.h>
#include <ud_file.h>

// Macro
# define ud_csv_read(path, have_header, ...)        ({ ud_arr *str = ud_file_read(path); ud_arr *csv = ud_csv_from_str(str, have_header, __VA_ARGS__); ud_arr_free(str); csv; })
# define ud_csv_from_str(str, have_header, ...)     ({ ud_arr *parsed = ud_stra_vrsplit(str, __VA_ARGS__); if (have_header && parsed->len > 0) ud_arr_frm_idx(parsed, 0); parsed; })

// Structures

// Prototypes

#endif

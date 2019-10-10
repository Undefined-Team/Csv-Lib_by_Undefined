#ifndef UD_CSV_H
# define UD_CSV_H

// Lib
#include <ud_string.h>
#include <ud_file.h>

// Macro
# define ud_csv_from_str(str, have_header, ...)     ud_csv_from_str_call(str, have_header, UD_ARGS_LEN(char*, __VA_ARGS__), __VA_ARGS__)


// Structures

// Prototypes
ud_arr          *ud_csv_from_str_call(ud_arr *str, ud_bool have_header, size_t args_len, ...);

#endif

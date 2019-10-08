#include "ud_csv.h"

static ud_arr   *ud_csv_read_rec(ud_arr *str, char **floor_sep)
{
    if (!*floor_sep) return NULL;
    char *sep = *floor_sep;
    ud_arr *splitted = ud_str_split(str, sep);
    if (splitted->type_s == 0)
    {
        size_t len = splitted->len;
        ud_arr **val = (ud_arr**)splitted->val;
        ud_arr *new_val;
        ++floor_sep;
        while (len-- > 0)
        {
            new_val = ud_csv_read_rec(*val, floor_sep);
            ud_arr_free(*val);
            *val++ = new_val;
        }
    }
    return splitted;
}

ud_arr          *ud_csv_from_str(ud_arr *str, ud_bool have_header, ...)
{
    va_list args;
    va_start(args, have_header);
    size_t args_len = (size_t)va_arg(args, size_t);
    char *sep[args_len + 1];
    sep[args_len] = NULL;
    char **sep_tmp = sep;
    while (args_len-- > 0) *sep_tmp++ = (char*)va_arg(args, char*);
    ud_arr *parsed = ud_csv_read_rec(str, sep);
    va_end(args);
    return parsed;     
}
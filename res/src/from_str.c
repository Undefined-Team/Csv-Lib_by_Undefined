#include "ud_csv.h"

static ud_arr   *ud_csv_read_rec(ud_arr *str, char **floor_sep)
{
    if (!floor_sep || !*floor_sep) return NULL;
    char *sep = *floor_sep;
    ++floor_sep;
    ud_arr *splitted = ud_stra_split(str, sep);
    if (splitted->type_s == 0 && *floor_sep)
    {
        size_t len = splitted->len;
        ud_arr **val = (ud_arr**)splitted->val;
        ud_arr *new_val;
        while (len-- > 0)
        {
            new_val = ud_csv_read_rec(*val, floor_sep);
            ud_arr_free(*val);
            *val++ = new_val;
        }
    }
    return splitted;
}

ud_arr          *ud_csv_from_str_call(ud_arr *str, ud_bool have_header, size_t args_len, ...)
{
    // (void)have_header;
    va_list args;
    va_start(args, args_len);
    char *sep[args_len + 1];
    char **sep_tmp = sep;
    while (args_len-- > 0) *sep_tmp++ = (char*)va_arg(args, char*);
    *sep_tmp = NULL;
    ud_arr *parsed = ud_csv_read_rec(str, sep);
    va_end(args);
    if (have_header && parsed->len > 0) ud_arr_rm_idx(parsed, 0);
    return parsed;
}
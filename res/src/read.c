#include "ud_csv.h"

ud_arr      *ud_csv_from_str(ud_arr *str, ud_bool have_header)
{
    ud_csv_param csv_param = ud_csv_param_set();
    ud_arr *parsed = ud_stra_rsplit(str, csv_param.sep);
    ud_stra_trim(parsed, csv_param.trim);
    if (have_header) ud_arr_frm_idx(parsed, 0);
    return parsed;
}

ud_arr      *ud_csv_read(char *path, ud_bool have_header)
{
    ud_arr *str = ud_file_read(path);
    ud_arr *csv = ud_csv_from_str(str, have_header);
    ud_arr_free(str);
    return csv;
}
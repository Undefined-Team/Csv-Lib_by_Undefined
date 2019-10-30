#include "ud_csv.h"

void      *ud_csv_from_str(char *str, ud_bool remove_header)
{
    ud_csv_param csv_param = ud_csv_param_get();
    char **parsed = ud_str_rsplit(str, csv_param.sep);
    size_t sep_nbr = ud_ptr_len(csv_param.sep);
    ud_str_rtrim(parsed, sep_nbr - 1, csv_param.trim);
    if (remove_header && sep_nbr) ud_ptr_rm_idx(parsed, 0, sep_nbr - 1);
    return parsed;
}

void      *ud_csv_read(char *path, ud_bool remove_header)
{
    char *str = ud_file_read(path);
    void *csv = ud_csv_from_str(str, remove_header);
    ud_ut_free(str);
    return csv;
}
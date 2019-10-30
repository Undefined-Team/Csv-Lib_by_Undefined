#include "ud_csv.h"

char  *ud_csv_to_str(void *csv)
{
    ud_csv_param csv_param = ud_csv_param_get();
    ud_str_rtrim(csv, ud_ptr_len(csv_param.sep) - 1, csv_param.trim);
    char *str = ud_str_rjoin(csv, csv_param.sep);
    return str;
}

void    ud_csv_write_ctr(char *path, void *csv, char **headers)
{
    char *str = ud_csv_to_str(csv);
    ud_file_clear(path);
    if (headers)
    {
        ud_csv_param csv_param = ud_csv_param_get();
        if (!*csv_param.sep) ud_ut_error("Headers param need csv param have at least one separator");
        ud_str_rtrim(headers, 0, csv_param.trim);
        char *joined = ud_str_fjoin(headers, *(csv_param.sep + 1) ? *(csv_param.sep + 1) : "");
        ud_file_write_append(path, joined);
        ud_file_write_append(path, *csv_param.sep);
        ud_ut_free(joined);
    }
    ud_file_write_append(path, str);
    ud_ut_free(str);
}
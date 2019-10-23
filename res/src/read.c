#include "ud_csv.h"

char      *ud_csv_from_str(char *str, ud_bool remove_header)
{
    ud_csv_param csv_param = ud_csv_param_set();
    char *parsed = ud_str_rsplit(str, csv_param.sep);
    ud_str_rtrim(parsed, csv_param.trim);
    if (remove_header)
    {
        size_t trim_len = ud_ptr_len(csv_param.sep);
        if (trim_len) ud_ptr_free(*parsed, trim_len);
    }
    return parsed;
}

char      *ud_csv_read(char *path, ud_bool remove_header)
{
    char *str = ud_file_read(path);
    char *csv = ud_csv_from_str(str, remove_header);
    ud_ut_free(str);
    return csv;
}
#include "ud_csv.h"

void __attribute__ ((destructor))  ud_csv_dtor() { ud_csv_param_free(); }

ud_csv_param        ud_csv_param_ctr(ud_csv_req req, char **new_param)
{
    static ud_csv_param csv_param = {.sep = NULL, .trim = NULL};
    if (csv_param.sep == NULL)
    {
        csv_param.sep = ud_ptr_set(char*, "\n", ",");
        csv_param.trim = ud_ptr_set(char*, " ", "\t", "\r", "\n");
    }
    if (req == ud_csv_sep)
    {
        if (!ud_ptr_len(new_param)) ud_ut_error("Csv separator param need at least one separator");
        ud_ut_free(csv_param.sep);
        csv_param.sep = new_param;
    }
    else if (req == ud_csv_trim)
    {
        ud_ut_free(csv_param.trim);
        csv_param.trim = new_param;
    }
    else if (req == ud_csv_free)
    {
        ud_ut_free(csv_param.trim);
        ud_ut_free(csv_param.sep);
    }
    return csv_param;
}
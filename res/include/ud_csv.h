#ifndef UD_CSV_H
# define UD_CSV_H

// Lib
#include <ud_string.h>
#include <ud_file.h>

// Macro
# define ud_csv_set_sep(...)                            ({ char **sep = ud_ptr_set(char*, __VA_ARGS__); (void)ud_csv_param_ctr(ud_csv_sep, sep); })
# define ud_csv_set_trim(...)                           ({ char **trim = ud_ptr_set(char*, __VA_ARGS__); (void)ud_csv_param_ctr(ud_csv_trim, trim); })
# define ud_csv_param_set()                             ud_csv_param_ctr(ud_csv_get, NULL)
# define ud_csv_param_free()                            (void)ud_csv_param_ctr(ud_csv_free, NULL)

// Structures
typedef enum        {ud_csv_get,ud_csv_free,ud_csv_sep,ud_csv_trim} ud_csv_req;

typedef struct      uds_csv_param {
    char            **sep;
    char            **trim;
}                   ud_csv_param;


// Prototypes
ud_csv_param        ud_csv_param_ctr(ud_csv_req req, char **new_param);
ud_arr              *ud_csv_from_str(ud_arr *str, ud_bool have_header);
ud_arr              *ud_csv_read(char *path, ud_bool have_header);

#endif

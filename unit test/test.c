#include <ud_csv.h>

int main(void)
{
    // char *csv = ud_str_dup("salut,ca\nva,bien\n");
    // ud_arr *csv_arr = ud_arr_new(sizeof(char), ud_str_len(csv), csv);
    // ud_arr_print(csv_arr, char, "%c");

    ud_arr *csv_arr = ud_file_read("test.csv");

    printf("before csv\n");
    ud_arr *parsed = ud_csv_from_str(csv_arr, false, "\n", ",", ";", ":");
    ud_arr_free(csv_arr);

    // ud_arr *parsed = ud_csv_read("test.csv", false, "\n");

    ud_arr_print(parsed, char, "%c");
    ud_arr_free(parsed);

    printf("\n\n");
    ud_arr *str = ud_stra_new("");
    printf("%zd %d\n", str->len, ((char*)str->val)[0]);
    ud_arr *splitted = ud_stra_split(str, ",");
    printf("%zd\n", splitted->len);
    ud_arr_print(splitted, char, "%c");
    return 0;
}
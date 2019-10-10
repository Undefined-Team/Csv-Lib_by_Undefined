#include <ud_csv.h>

int main(void)
{
    // ud_arr *split_test

    char *csv = ud_str_dup("test,test2\ntt,to");
    ud_arr *csv_arr = ud_arr_new(sizeof(char), ud_str_len(csv), csv);
    ud_arr_print(csv_arr, char, "%c");

    // ud_arr *parsed = ud_stra_split(csv_arr, "5");
    printf("before csv\n");
    ud_arr *parsed = ud_csv_from_str(csv_arr, false, "\n", ",");
    ud_arr_print(parsed, char, "%c");
    return 0;
}
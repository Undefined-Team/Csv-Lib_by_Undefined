#include <ud_csv.h>

// # define test_change(macro) ({ #define TESTMAC TESTMAC ## macro # define TESTNRM #TESTMAC

int main(void)
{
    // Test csv from str

    // Test csv read
    ud_arr *csv = ud_csv_read("test.csv", false);
    ud_arr_print(csv);
    ud_arr_free(csv);

    ud_csv_set_trim("cc", "ss");

    csv = ud_csv_read("test.csv", false);
    ud_arr_print(csv);
    ud_arr_free(csv);
    return 0;
}
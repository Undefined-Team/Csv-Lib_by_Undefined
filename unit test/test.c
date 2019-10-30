#include <ud_csv.h>

int main(void)
{
    // Test csv from str

    // Test csv read
    char ***csv = ud_csv_read("test.csv", true);
    ud_csv_set_trim("cc", "ss");
    printf("after csv\n");
    printf("%s\n", (*csv)[1]);
    ud_csv_write("test3.csv", csv, "imaheader", "yes");
    ud_ptr_free(csv, 2);
    // printf("%s\n", csv[0][1]);

    return 0;
}
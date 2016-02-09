#include "problems.h"
#include <stdio.h>

void p54(void)
{
    const char *poker_filename = "p54_data.txt";
    char error_msg[64];
    FILE *poker_file = NULL;
    int i, j;

    poker_file = fopen(poker_filename, "r");
    if (poker_file == NULL) {
        snprintf(error_msg, 64, "Failed to open %s", poker_filename);
        perror(error_msg);
        return;
    }
}

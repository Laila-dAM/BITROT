#include <stdio.h>
#include "cli.h"

int main(int argc, char *argv[]) {
    printf("DataHub CLI starting...\n");
    handle_command(argc, argv);
    return 0;
}

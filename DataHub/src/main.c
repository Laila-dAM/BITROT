#include <stdio.h>
#include "cli.h"
#include "config.h"

int main(int argc, char *argv[]) {
    printf("DataHub CLI starting...\n");
    handle_command(argc, argv);
    return 0;
}

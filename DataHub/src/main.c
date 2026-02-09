#include <stdio.h>
#include "cli.h"
#include "config.h"

int main(int argc, char *argv[]) {
    Config config;

    if (!load_config("config/datahub.conf", &config)) {
        printf("Warning: could not load config file.\n");
    }

    printf("DataHub CLI starting...\n");
    handle_command(argc, argv);

    return 0;
}

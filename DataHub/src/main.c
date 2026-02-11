#include <stdio.h>
#include "core/app.h"
#include "core/menu.h"
#include "database/connection.h"
#include "security/access_control.h"
#include "utils/logger.h"

int main() {
    if (db_connect() != 0) {
        printf("Failed to connect to the database.\n");
        return 1;
    }

    log_info("Application started");

    app_initialize();
    cli_main_menu();

    log_info("Application exited");
    db_disconnect();

    return 0;
}

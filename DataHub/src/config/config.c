#include <stdio.h>
#include <stdlib.h>
#include "config.h"

typedef struct {
    char host[256];
    int port;
    char database[256];
    char user[256];
    char password[256];
} DBConfig;

static DBConfig db_config;

void load_config() {
    snprintf(db_config.host, sizeof(db_config.host), "%s", DB_HOST);
    db_config.port = DB_PORT;
    snprintf(db_config.database, sizeof(db_config.database), "%s", DB_NAME);
    snprintf(db_config.user, sizeof(db_config.user), "%s", DB_USER);
    snprintf(db_config.password, sizeof(db_config.password), "%s", DB_PASSWORD);
}

DBConfig* get_db_config() {
    return &db_config;
}

#include <stdio.h>
#include <time.h>
#include <mysql/mysql.h>
#include "../database/db.h"
#include "logger.h"

void log_info(const char *message) {
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    printf("[%04d-%02d-%02d %02d:%02d:%02d] INFO: %s\n",
        tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday,
        tm.tm_hour, tm.tm_min, tm.tm_sec, message);
}

void log_error(const char *message) {
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    printf("[%04d-%02d-%02d %02d:%02d:%02d] ERROR: %s\n",
        tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday,
        tm.tm_hour, tm.tm_min, tm.tm_sec, message);
}

void log_action(const char *username, const char *action) {
    MYSQL *conn = db_get_connection();
    if (!conn) return;

    char query[512];
    snprintf(query, sizeof(query),
        "INSERT INTO access_logs(user_id, action, timestamp) "
        "VALUES((SELECT id FROM users WHERE username='%s'), '%s', NOW())",
        username, action);

    if (mysql_query(conn, query)) {
        fprintf(stderr, "Failed to log action: %s\n", mysql_error(conn));
    }
}

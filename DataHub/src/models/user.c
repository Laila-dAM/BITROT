#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sqlite3.h>
#include "../database/db.h"
#include "user.h"

int create_user_db(const char *username, const char *password_hash, const char *email) {
    char query[512];
    snprintf(query, sizeof(query),
             "INSERT INTO users (username, password_hash, email) VALUES ('%s', '%s', '%s')",
             username, password_hash, email);
    return db_execute_query(query);
}

int update_user_db(int id, const char *username, const char *password_hash, const char *email) {
    char query[512];
    snprintf(query, sizeof(query),
             "UPDATE users SET username='%s', password_hash='%s', email='%s' WHERE id=%d",
             username, password_hash, email, id);
    return db_execute_query(query);
}

int delete_user_db(int id) {
    char query[256];
    snprintf(query, sizeof(query), "DELETE FROM users WHERE id=%d", id);
    return db_execute_query(query);
}

int get_user_by_id(int id, User *user) {
    char query[256];
    snprintf(query, sizeof(query), "SELECT id, username, password_hash, email FROM users WHERE id=%d", id);
    sqlite3 *db_conn = db_get_connection();
    if (db_conn == NULL) return 1;

    char *err_msg = NULL;
    int callback(void *data, int argc, char **argv, char **colName) {
        user->id = atoi(argv[0]);
        strncpy(user->username, argv[1], 50);
        strncpy(user->password_hash, argv[2], 255);
        strncpy(user->email, argv[3], 100);
        return 0;
    }

    int rc = sqlite3_exec(db_conn, query, callback, 0, &err_msg);
    if (rc != SQLITE_OK) {
        sqlite3_free(err_msg);
        return 1;
    }
    return 0;
}

int get_user_by_username(const char *username, User *user) {
    char query[256];
    snprintf(query, sizeof(query), "SELECT id, username, password_hash, email FROM users WHERE username='%s'", username);
    sqlite3 *db_conn = db_get_connection();
    if (db_conn == NULL) return 1;

    char *err_msg = NULL;
    int callback(void *data, int argc, char **argv, char **colName) {
        user->id = atoi(argv[0]);
        strncpy(user->username, argv[1], 50);
        strncpy(user->password_hash, argv[2], 255);
        strncpy(user->email, argv[3], 100);
        return 0;
    }

    int rc = sqlite3_exec(db_conn, query, callback, 0, &err_msg);
    if (rc != SQLITE_OK) {
        sqlite3_free(err_msg);
        return 1;
    }
    return 0;
}

int list_all_users() {
    const char *query = "SELECT id, username, email FROM users";
    sqlite3 *db_conn = db_get_connection();
    if (db_conn == NULL) return 1;

    char *err_msg = NULL;
    int callback(void *NotUsed, int argc, char **argv, char **colName) {
        printf("ID: %s | Username: %s | Email: %s\n", argv[0], argv[1], argv[2]);
        return 0;
    }

    printf("\n=== Users List ===\n");
    int rc = sqlite3_exec(db_conn, query, callback, 0, &err_msg);
    if (rc != SQLITE_OK) {
        sqlite3_free(err_msg);
        return 1;
    }
    return 0;
}

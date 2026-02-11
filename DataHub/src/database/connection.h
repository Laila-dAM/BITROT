#ifndef CONNECTION_H
#define CONNECTION_H

#include <sqlite3.h>

sqlite3* create_connection();
void close_connection(sqlite3 *db);
int test_connection(sqlite3 *db);

#endif

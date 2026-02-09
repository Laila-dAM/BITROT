#ifndef DB_H
#define DB_H

#include <sqlite3.h>

int db_open(const char *db_path);
void db_close(void);
int db_init_schema(const char *schema_file);
int db_is_connected(void);

#endif

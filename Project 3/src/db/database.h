#ifndef DATABASE_H
#define DATABASE_H

#include <sqlite3.h>

int db_open(const char *path);
void db_close(void);
sqlite3 *db_get(void);

#endif

#include <stdlib.h>
#include "database.h"

static sqlite3 *database = NULL;

int db_open(const char *path)
{
    if (sqlite3_open(path, &database) != SQLITE_OK)
    {
        return 1;
    }
    return 0;
}

void db_close(void)
{
    if (database)
    {
        sqlite3_close(database);
        database = NULL;
    }
}

sqlite3 *db_get(void)
{
    return database;
}

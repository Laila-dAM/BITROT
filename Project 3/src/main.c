#include <stdio.h>
#include <sqlite3.h>

int main() {
    sqlite3 *db;
    int rc = sqlite3_open("stockcore.db", &db);

    if (rc) {
        printf("Cannot open database\n");
        return 1;
    }

    printf("StockCore CLI started successfully\n");

    sqlite3_close(db);
    return 0;
}

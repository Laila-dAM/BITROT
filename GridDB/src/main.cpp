#include "cli/cli.h"
#include "core/database.h"
#include "storage/file_manager.h"
#include "query/lexer.h"
#include "query/parser.h"
#include "query/executor.h"
#include "index/hash_index.h"
#include "index/btree.h"
#include "utils/logger.h"

int main(int argc, char* argv[]) {
    Logger::init("GridDB.log");

    Database db("data/example.db");

    CLI cli(&db);
    cli.run();

    return 0;
}
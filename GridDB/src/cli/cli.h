#ifndef CLI_H
#define CLI_H

#include <string>
#include "core/database.h"

class CLI {
public:
    CLI(Database* db);
    void run();
private:
    Database* db_;
    void executeCommand(const std::string& command);
    void showPrompt();
};

#endif
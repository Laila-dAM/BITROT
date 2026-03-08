#include "cli.h"
#include <iostream>
#include <sstream>

CLI::CLI(Database* db) : db_(db) {}

void CLI::run() {
    std::string input;
    while (true) {
        showPrompt();
        std::getline(std::cin, input);
        if (input == "exit" || input == "quit") {
            break;
        }
        if (!input.empty()) {
            executeCommand(input);
        }
    }
}

void CLI::showPrompt() {
    std::cout << "GridDB> ";
    std::cout.flush();
}

void CLI::executeCommand(const std::string& command) {
    std::istringstream iss(command);
    std::string cmd;
    iss >> cmd;

    if (cmd == "select" || cmd == "insert" || cmd == "delete" || cmd == "create") {
        db_->executeQuery(command);
    } else if (cmd == "help") {
        std::cout << "Commands: create, select, insert, delete, exit\n";
    } else {
        std::cout << "Unknown command: " << cmd << "\n";
    }
}
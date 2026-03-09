#pragma once
#include <memory>
#include <vector>
#include <string>

#include "../core/database.h"

#include "ast/statement.h"
#include "ast/create_table.h"
#include "ast/insert.h"
#include "ast/select.h"
#include "ast/delete.h"

class Executor
{
private:
    Database& database;

    void executeCreateTable(const CreateTableStatement& stmt);
    void executeInsert(const InsertStatement& stmt);
    std::vector<std::vector<std::string>> executeSelect(const SelectStatement& stmt);
    void executeDelete(const DeleteStatement& stmt);

public:
    Executor(Database& db);

    std::vector<std::vector<std::string>> execute(std::unique_ptr<Statement> stmt);
};
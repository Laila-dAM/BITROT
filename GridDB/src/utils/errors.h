#pragma once
#include <stdexcept>
#include <string>

class DatabaseException : public std::runtime_error
{
public:
    explicit DatabaseException(const std::string& message)
        : std::runtime_error(message) {}
};

class TableNotFoundException : public DatabaseException
{
public:
    explicit TableNotFoundException(const std::string& table)
        : DatabaseException("Table not found: " + table) {}
};

class ColumnNotFoundException : public DatabaseException
{
public:
    explicit ColumnNotFoundException(const std::string& column)
        : DatabaseException("Column not found: " + column) {}
};

class DuplicateTableException : public DatabaseException
{
public:
    explicit DuplicateTableException(const std::string& table)
        : DatabaseException("Table already exists: " + table) {}
};

class InvalidQueryException : public DatabaseException
{
public:
    explicit InvalidQueryException(const std::string& message)
        : DatabaseException("Invalid query: " + message) {}
};

class StorageException : public DatabaseException
{
public:
    explicit StorageException(const std::string& message)
        : DatabaseException("Storage error: " + message) {}
};
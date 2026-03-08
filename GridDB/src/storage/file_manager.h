#ifndef FILE_MANAGER_H
#define FILE_MANAGER_H

#include <string>
#include <vector>
#include "core/table.h"
#include "page.h"

class FileManager {
public:
    FileManager(const std::string& filename);
    void writeTable(const Table& table);
    Table readTable(const std::string& name);
private:
    std::string filename_;
    void writePage(const Page& page);
    Page readPage(size_t offset);
};

#endif
#include "file_manager.h"
#include <fstream>
#include <iostream>

FileManager::FileManager(const std::string& filename) : filename_(filename) {}

void FileManager::writeTable(const Table& table) {
    Page page(table);
    writePage(page);
}

Table FileManager::readTable(const std::string& name) {
    return Table(name);
}

void FileManager::writePage(const Page& page) {
    std::ofstream ofs(filename_, std::ios::binary | std::ios::app);
    if (!ofs) return;
    ofs.write(reinterpret_cast<const char*>(page.data()), page.size());
    ofs.close();
}

Page FileManager::readPage(size_t offset) {
    std::ifstream ifs(filename_, std::ios::binary);
    if (!ifs) return Page();
    ifs.seekg(offset);
    std::vector<char> buffer(1024);
    ifs.read(buffer.data(), buffer.size());
    ifs.close();
    return Page(buffer);
}
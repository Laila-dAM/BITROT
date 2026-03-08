#ifndef PAGE_H
#define PAGE_H

#include <vector>
#include "core/table.h"

class Page {
public:
    Page();
    Page(const Table& table);
    const std::vector<char>& data() const;
    size_t size() const;
private:
    std::vector<char> buffer_;
};

#endif
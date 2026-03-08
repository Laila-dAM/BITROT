#include "page.h"
#include "serializer.h"

Page::Page() {}

Page::Page(const Table& table) {
    buffer_ = Serializer::serializeTable(table);
}

const std::vector<char>& Page::data() const {
    return buffer_;
}

size_t Page::size() const {
    return buffer_.size();
}
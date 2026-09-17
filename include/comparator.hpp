#pragma once

#include <unordered_map>
#include <vector>
#include <string>

#include "types.hpp"
#include "grouper.hpp"

using DuplicateMap = std::unordered_map<std::string, std::vector<FileData>>;

class Comparator {
private:
    DuplicateMap results;

public:
    // * Main
    void compare(const FileGroup& groups);

    // * Helpers

    // * Properties
    const DuplicateMap& get_duplicates() const;
};
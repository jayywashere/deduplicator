#pragma once

#include <unordered_map>
#include <vector>

#include "types.hpp"

using FileGroup = std::unordered_map<std::uintmax_t, std::vector<FileData>>;

class Grouper {
private:
    FileGroup groups;

public:
    // * Main
    void group(const std::vector<FileData>& files);

    // * Helpers

    // * Properties
    const FileGroup get_groups() const;
};
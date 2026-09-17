#pragma once

#include <filesystem>
#include <string>
#include <vector>

#include "types.hpp"

class Scanner {
private:
    std::vector<FileData> files;

public:
    // * Main
    void scan(const std::filesystem::path& path, bool recursive);

    // * Helpers
    void process_entry(const std::filesystem::directory_entry& entry);

    // * Properties
    const std::vector<FileData>& get_files() const;
};
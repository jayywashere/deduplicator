#pragma once

#include <filesystem>

struct FileData {
    std::filesystem::path absolute_path;
    std::uintmax_t size;
};
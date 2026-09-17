#include <sstream>
#include <fstream>
#include <filesystem>
#include <functional>

#include "comparator.hpp"

const std::string get_hash(const std::filesystem::path& path) {
    std::ifstream file(path, std::ios::binary);
    if (!file.is_open()) {
        return "";
    }

    std::stringstream buffer;
    buffer << file.rdbuf();
    std::string file_content = buffer.str();

    size_t raw_hash = std::hash<std::string>{}(file_content);
    return std::to_string(raw_hash);
}

void Comparator::compare(const FileGroup& groups) {
    results.clear();

    for (const auto& pair : groups) {
        for (const auto& file : pair.second) {
            const std::string hash = get_hash(file.absolute_path);
            results[hash].push_back(file);
        }
    }

    std::erase_if(results, [](const auto& pair){
        return pair.second.size() < 2;
    });
}

const DuplicateMap& Comparator::get_duplicates() const {
    return results;
}
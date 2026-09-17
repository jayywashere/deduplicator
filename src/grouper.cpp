#include "grouper.hpp"

void Grouper::group(const std::vector<FileData>& files) {
    groups.clear();

    if (files.empty()) {
        return;
    }

    for (const auto& file : files) {
        groups[file.size].push_back(file);
    }

    std::erase_if(groups, [](const auto& pair) {
        return pair.second.size() < 2;
    });
}

const FileGroup Grouper::get_groups() const {
    return groups;
}
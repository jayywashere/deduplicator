#include <print>
#include <string>

#include "reporter.hpp"

void Reporter::report(const DuplicateMap& duplicates) const {
    if (duplicates.empty()) {
        std::println("No duplicate files found! Your drive is clean.");
        return;
    }

    std::println("{0:=<65}\n{1:^65}\n{0:=<65}", "", "DUPLICATE FILE REPORT");

    int group_num = 1;

    for (const auto& [hash, file_list] : duplicates) {
        std::uintmax_t file_size = file_list.front().size;

        std::println("\n[Group #{}] - Size: {} bytes", group_num++, file_size);
        std::println("{}", std::string(65, '-'));

        for (const auto& file : file_list) {
            std::println("  {:<60}", file.absolute_path.string());
        }
    }

    std::println("\n{}", std::string(65, '='));
}
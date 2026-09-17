#include <stdexcept>

#include "scanner.hpp"

void Scanner::scan(const std::filesystem::path& path, bool recursive) {
    files.clear();
    
    if (!std::filesystem::exists(path)) {
        throw std::invalid_argument(
            "The provided path does not exist: "
                + path.string()
            );
    }

    if (recursive) {
        for (const auto& entry : std::filesystem::recursive_directory_iterator(path)) {
            process_entry(entry);
        }
    } else {
        for (const auto& entry : std::filesystem::directory_iterator(path)) {
            process_entry(entry);
        }
    }
}

const std::vector<FileData>& Scanner::get_files() const {
    return files;
}

void Scanner::process_entry(const std::filesystem::directory_entry& entry) {
    if (entry.is_regular_file()) {
        FileData file;
        file.absolute_path = entry.path();
        file.size = entry.file_size();

        files.push_back(file);
    }
}
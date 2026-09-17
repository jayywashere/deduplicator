#include <print>
#include <iostream>
#include <string>
#include <filesystem>
#include <stdexcept>

#include "scanner.hpp"
#include "grouper.hpp"
#include "comparator.hpp"
#include "reporter.hpp"
#include "utils/input.hpp"

int main() {
    std::println("Welcome to the deduplicator!");

    while (true) {
        std::print("\nEnter a directory path, or type 'q' to exit:\n> ");
        const ui::Input input = ui::read_line();

        if (input.result == ui::InputResult::EndOfInput) {
            std::println("\nInput closed.");
            break;
        }

        if (input.result == ui::InputResult::Exit) {
            break;
        }

        if (input.value.empty()) {
            std::println("Please enter a path.");
            continue;
        }

        std::filesystem::path target_folder { input.value };

        try {
            Scanner scanner;
            scanner.scan(target_folder, true);
    
            Grouper grouper;
            grouper.group(scanner.get_files());
    
            Comparator comparator;
            comparator.compare(grouper.get_groups());
    
            Reporter reporter;
            reporter.report(comparator.get_duplicates());
        }
        
        catch (const std::invalid_argument& err) {
            std::println("\nConfiguration error: {}", err.what());
            return 1;
        }
        
        catch (const std::exception& err) {
            std::println("\nAn unexpected error occurred: {}", err.what());
            return 1;
        }
    }

    std::println("Goodbye!");
    return 0;
}
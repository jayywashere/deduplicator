#include <iostream>

#include "utils/input.hpp"

namespace ui {

Input read_line() {
    std::string raw_input;
    std::getline(std::cin, raw_input);

    if (!std::cin) {
        return {
            .result = InputResult::EndOfInput,
            .value = {}
        };
    }

    std::string input = trim(raw_input);

    if (input == "q" or input == "quit" or input == "exit") {
        return {
            .result = InputResult::Exit,
            .value = input
        };
    }

    return {
        .result = InputResult::Value,
        .value = input
    };
}

std::string trim(const std::string& str) {
    const std::string whitespace = "\t\r\n";
    const auto str_begin = str.find_first_not_of(whitespace);
    if (str_begin == std::string::npos) return "";

    const auto str_end = str.find_last_not_of(whitespace);
    const auto str_range = str_end - str_begin + 1;

    return str.substr(str_begin, str_range);
}

}
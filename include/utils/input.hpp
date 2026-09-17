#pragma once

#include <string>
#include <print>

namespace ui {

enum class InputResult {
    Value, Exit, EndOfInput
};

struct Input {
    InputResult result;
    std::string value;
};

// * Main

Input read_line();
Input prompt(const std::string& prompt);

// * Helpers

std::string trim(const std::string& str);

// * Properties


}
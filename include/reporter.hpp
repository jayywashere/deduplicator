#pragma once

#include "comparator.hpp"

class Reporter {
public:
    // * Main
    void report(const DuplicateMap& duplicates) const;
};
#pragma once

#include <iostream>

#include "../Services/Timer.h"

std::pair<int64_t, int64_t> native_search(const std::string& text, const std::string& pattern) {
    auto start = std::chrono::high_resolution_clock::now();
    size_t text_length = text.length(), pattern_length = pattern.length();
    if (text_length < pattern_length) {
        return {get_time(start), -1};
    }

    int64_t index = -1;
    for (size_t i = 0; i <= text_length - pattern_length; ++i) {
        bool match = true;
        for (size_t j = 0; j < pattern_length; ++j) {
            if (pattern[j] != '?' && text[i + j] != pattern[j]) {
                match = false;
                break;
            }
        }
        if (match) {
            // Это я заигнорил, потому что в рамках работы не предусматривается работа со значениями длины
            // строки / подстроки > 100.000 => не будет переполнения или чего-то похожего ID
            index = i;
        }
    }
    return {get_time(start), index};
}
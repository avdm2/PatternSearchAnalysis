#pragma once

#include <iostream>
#include <vector>

#include "../Services/Timer.h"

std::vector<size_t> calculate_prefix(const std::string& pattern) {
    size_t pattern_length = pattern.length();
    std::vector<size_t> prefix_function(pattern_length, 0);

    size_t j = 0;
    for (size_t i = 1; i < pattern_length; ++i) {
        while (j > 0 && (pattern[i] != pattern[j] && pattern[j] != '?')) {
            j = prefix_function[j - 1];
        }
        if (pattern[i] == pattern[j] || pattern[j] == '?' || pattern[i] == '?') {
            ++j;
        }
        prefix_function[i] = j;
    }
    return prefix_function;
}

std::vector<size_t> calculate_optimized_prefix(const std::string& pattern) {
    size_t pattern_length = pattern.length();
    std::vector<int> prefix_function(pattern_length, 0);
    std::vector<size_t> optimized_prefix_function(pattern_length, 0);

    int j = 0;
    for (size_t i = 1; i < pattern_length; ++i) {
        while (j > 0 && (pattern[i] != pattern[j] && pattern[j] != '?')) {
            j = prefix_function[j - 1];
        }
        if (pattern[i] == pattern[j] || pattern[j] == '?') {
            ++j;
        }
        prefix_function[i] = j;
        optimized_prefix_function[i] = (j > 0 && pattern[i - j] != '?' && pattern[i] != pattern[i - j]) ? optimized_prefix_function[j - 1] : i;
    }
    return optimized_prefix_function;
}

std::pair<int64_t, int64_t> kmp(const std::string& text, const std::string& pattern, const char& type) {
    auto start = std::chrono::high_resolution_clock::now();
    size_t text_length = text.length(), pattern_length = pattern.length();
    std::vector<size_t> prefix = type == 's' ? calculate_prefix(pattern) : calculate_optimized_prefix(pattern);
    size_t j = 0;
    int64_t index = -1;

    for (size_t i = 0; i < text_length; ++i) {
        while (j > 0 && (text[i] != pattern[j] && pattern[j] != '?')) {
            j = prefix[j - 1];
        }
        if (text[i] == pattern[j] || pattern[j] == '?') {
            ++j;
        }
        if (j == pattern_length) {
            // Это я заигнорил, потому что в рамках работы не предусматривается работа со значениями длины
            // строки / подстроки > 100.000 => не будет переполнения или чего-то похожего ID
            index = i - pattern_length + 1;
            j = prefix[j - 1];
        }
    }
    return {get_time(start), index};
}

std::pair<int64_t, int64_t> kmp_simple(const std::string& text, const std::string& pattern) {
    return kmp(text, pattern, 's');
}

std::pair<int64_t, int64_t> kmp_optimized(const std::string& text, const std::string& pattern) {
    return kmp(text, pattern, 'o');
}
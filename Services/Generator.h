#pragma once

#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>

// Замечание: индекс, с которого будет формироваться паттерн, лежит в диапазоне от [0, 99].

std::string get_binary_text(const size_t& size) {
    srand(time(nullptr));
    std::string text(size, '0');
    for (size_t i = 0; i < size; ++i) {
        text[i] = '0' + (rand() % 2);
    }
    return text;
}

std::string get_text(const size_t& size) {
    srand(time(nullptr));
    std::string text(size, '0');
    for (size_t i = 0; i < size; ++i) {
        text[i] = '0' + (rand() & 4);
    }
    return text;
}

std::string get_pattern(const std::string& text, const size_t& size) {
    srand(time(nullptr));
    size_t index = rand() % 100;
    std::string pattern(size, '0');
    for (size_t i = index; i < index + size; ++i) {
        pattern[i - index] = text[i];
    }
    return pattern;
}

std::string get_wildcard_pattern(const std::string& text, const size_t& size, const int& wildcards_amount) {
    srand(time(nullptr));
    size_t index = rand() % 100;
    std::string pattern(size, '0');
    for (size_t i = index; i < index + size; ++i) {
        pattern[i - index] = text[i];
    }
    for (int i = 0; i < wildcards_amount; ++i) {
        pattern[rand() % pattern.length()] = '?';
    }
    return pattern;
}
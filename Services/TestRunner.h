#include "Generator.h"
#include "AverageCalculator.h"
#include "Writer.h"

#include "../SearchMethods/NativeSearch.h"
#include "../SearchMethods/KMP.h"

void run_tests() {
    std::vector<std::string> texts(TESTS_AMOUNT), patterns(TESTS_AMOUNT);
    std::vector<std::function<std::pair<int64_t, int64_t>(const std::string&,
                                                          const std::string&)>> algorithms = {native_search,
                                                                                              kmp_simple,
                                                                                              kmp_optimized};
    std::vector<std::string> names = {"Native", "KMP", "KMP_O"};

    for (size_t pattern_size = 100; pattern_size <= 3000; pattern_size += 100) {
        for (size_t text_size : {10000, 100000}) {
            for (int alphabet_size : {2, 4}) {
                for (int wildcards : {0, 1, 2, 3, 4}) {
                    for (int i = 0; i < TESTS_AMOUNT; ++i) {
                        std::string text = (alphabet_size == 2) ? get_binary_text(text_size) : get_text(text_size);
                        std::string pattern = (wildcards == 0) ? get_pattern(text, pattern_size) : get_wildcard_pattern(text, pattern_size, wildcards);
                        texts[i] = text;
                        patterns[i] = pattern;
                    }
                    for (int i = 0; i < algorithms.size(); ++i) {
                        auto avg = average_time(texts, patterns, algorithms[i]);
                        write_CSV(names[i], text_size, alphabet_size, pattern_size, wildcards, avg);
                    }
                }
            }
        }
    }
}

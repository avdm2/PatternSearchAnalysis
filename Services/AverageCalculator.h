#include <vector>
#include <functional>

#include "Generator.h"

#define TESTS_AMOUNT 100

int64_t average_time(const std::vector<std::string>& texts, const std::vector<std::string>& patterns,
                     const std::function<std::pair<int64_t, int64_t>(const std::string&, const std::string&)>& func) {
    int64_t sum = 0;
    for (int i = 0; i < TESTS_AMOUNT; ++i) {
        sum += func(texts[i], patterns[i]).first;
    }
    return sum / TESTS_AMOUNT;
}
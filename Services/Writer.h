#include <iostream>
#include <fstream>

void write_header() {
    std::ofstream file("../Output/data.csv", std::ios_base::app);
    file << "Method;Text size;Alphabet size;Pattern size;Wildcards;Time" << "\n";
    file.close();
}

void write_CSV(const std::string& func, const size_t& text_size, const int& alphabet_size,
               const size_t& pattern_size, const int& wildcards, const int64_t& time) {
    std::ofstream file("../Output/data.csv", std::ios_base::app);
    file << func << ";" << text_size << ";" << alphabet_size << ";" << pattern_size << ";" << wildcards << ";" << time << "\n";
    file.close();
}

void clear_CSV() {
    std::ofstream file("../Output/data.csv", std::ios::out);
    file.close();
}
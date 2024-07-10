#include "test.h"
#include <chrono>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <vector>

constexpr auto MAX_EXERCISE = 14;

int main(int argc, char **argv) {
    if (argc == 1) {
        std::vector<bool> result(MAX_EXERCISE + 1, false);
        auto success = 0;
        for (auto i = 0; i <= MAX_EXERCISE; ++i) {
            if (test_exercise(i, nullptr)) {
                result[i] = true;
                ++success;
            }
        }

        std::cout << success << "/" << MAX_EXERCISE + 1 << " [";
        for (auto b : result) {
            std::cout << (b ? "\x1b[32m#\x1b[0m" : "\x1b[31mX\x1b[0m");
        }
        std::cout << ']' << std::endl;
        return EXIT_SUCCESS;
    }
    if (argc == 2 && std::strcmp(argv[1], "--simple") == 0) {
        auto time = std::chrono::system_clock::now();
        auto time_ = std::chrono::system_clock::to_time_t(time);
        std::stringstream ss;
        ss << std::put_time(std::localtime(&time_), "%Y-%m-%d-%H-%M-%S") << ".log";
        auto log_file = ss.str();

        auto success = 0;
        for (auto i = 0; i <= MAX_EXERCISE; ++i) {
            if (test_exercise(i, log_file.c_str())) {
                ++success;
            }
        }

        std::cout << success << "/" << MAX_EXERCISE + 1 << std::endl;
        return EXIT_SUCCESS;
    }
    std::cerr << "Usage: xmake run summary [--simple]" << std::endl;
    return EXIT_FAILURE;
}

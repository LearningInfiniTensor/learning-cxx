#include "test.h"
#include <chrono>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <numeric>
#include <sstream>
#include <thread>
#include <vector>

constexpr auto MAX_EXERCISE = 29;

int main(int argc, char **argv) {
    if (argc == 1) {
        Log log{Console{}};
        for (auto i = 0; i <= MAX_EXERCISE; ++i) {
            log << i;
        }
        std::cout << std::accumulate(log.result.begin(), log.result.end(), 0, std::plus{}) << '/' << MAX_EXERCISE + 1 << " [";
        for (auto b : log.result) {
            std::cout << (b ? "\x1b[32m#\x1b[0m" : "\x1b[31mX\x1b[0m");
        }
        std::cout << ']' << std::endl;
        return EXIT_SUCCESS;
    }
    if (argc == 2 && std::strcmp(argv[1], "--simple") == 0) {
        Log log{Null{}};
        std::vector<std::thread> threads;
        for (auto i = 0; i <= MAX_EXERCISE; ++i) {
            threads.emplace_back([&log, i]() { log << i; });
        }
        for (auto i = 0; i <= MAX_EXERCISE; ++i) {
            threads[i].join();
        }
        std::cout << std::accumulate(log.result.begin(), log.result.end(), 0, std::plus{}) << '/' << MAX_EXERCISE + 1 << std::endl;
        return EXIT_SUCCESS;
    }
    std::cerr << "Usage: xmake run summary [--simple]" << std::endl;
    return EXIT_FAILURE;
}

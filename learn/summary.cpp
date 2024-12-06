#include "test.h"
#include <atomic>
#include <chrono>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <numeric>
#include <sstream>
#include <thread>
#include <vector>

constexpr auto MAX_EXERCISE = 33;

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
        auto concurrency = std::thread::hardware_concurrency();
        if (concurrency == 0) {
            concurrency = 1;
        }

        std::atomic_int k{0};
        std::vector<std::thread> threads;
        threads.reserve(concurrency);

        std::cout << "concurrency: " << concurrency << std::endl;
        Log log{Null{}};
        for (auto i = 0u; i <= concurrency; ++i) {
            threads.emplace_back([i, &log, &k] {
                int j = k.fetch_add(1);
                while (j <= MAX_EXERCISE) {
                    std::printf("run %d at %d\n", j, i);
                    log << j;
                    j = k.fetch_add(1);
                }
            });
        }
        for (auto &thread : threads) {
            thread.join();
        }

        std::cout << std::accumulate(log.result.begin(), log.result.end(), 0, std::plus{}) << '/' << MAX_EXERCISE + 1 << std::endl;
        return EXIT_SUCCESS;
    }
    std::cerr << "Usage: xmake run summary [--simple]" << std::endl;
    return EXIT_FAILURE;
}

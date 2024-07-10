#include <cstdlib>
#include <filesystem>
#include <iostream>
#include <string>

#ifndef __XMAKE__
#define __XMAKE__ "XMAKE is not defined"
#endif

namespace fs = std::filesystem;
constexpr static auto XMAKE = __XMAKE__;

int process_run(const char *cmd, const char *proj) {
    static auto exercises = fs::absolute(fs::path(XMAKE) / "exercises");
    auto prefix = std::string("xmake ") + cmd + " -P " + exercises.string() + ' ' + proj;
    return std::system(prefix.c_str());
}

bool test_exercise(int n) {
    char str[] = "exerciseXX";
    std::sprintf(str, "exercise%02d", n);
    return process_run("", str) == 0 && process_run("run", str) == 0;
}

int main(int argc, char **argv) {
    switch (argc) {
        case 2: {
            int num;
            if (1 != std::sscanf(argv[1], "%d", &num)) {
                std::cerr << "Invalid exercise number: " << argv[1] << std::endl;
                return 1;
            };
            if (!test_exercise(num)) {
                return 1;
            }
            break;
        }
        case 1: {
            constexpr auto MAX_EXERCISE = 22;
            auto success = 0;
            for (auto i = 0; i <= MAX_EXERCISE; ++i) {
                if (test_exercise(i)) {
                    ++success;
                }
            }
            std::cout << success << "/" << MAX_EXERCISE + 1 << std::endl;
            break;
        }
        default:
            std::cerr << "Usage: xmake run learn <exercice number>" << std::endl;
            return 1;
    }

    return 0;
}

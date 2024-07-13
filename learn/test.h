#ifndef __TEST_H__
#define __TEST_H__

#include <filesystem>
#include <mutex>
#include <variant>
#include <vector>

struct Console {};
struct Null {};
struct Log {
    std::variant<Console, Null, std::filesystem::path> dst;
    std::vector<bool> result;
    std::mutex mutex;
    Log &operator<<(unsigned int n);
};

#endif// __TEST_H__

#include "../exercise.h"
#include <array>
#include <cstring>

// READ: std::array <https://zh.cppreference.com/w/cpp/container/array>

// TODO: 将下列 `?` 替换为正确的代码
int main(int argc, char **argv) {
    {
        std::array<int, 5> arr{{1, 2, 3, 4, 5}};
        ASSERT(arr.size() == ?, "Fill in the correct value.");
        ASSERT(sizeof(arr) == ?, "Fill in the correct value.");
        int ans[]{1, 2, 3, 4, 5};
        ASSERT(std::memcmp(arr.?, ans, ?) == 0, "Fill in the correct values.");
    }
    {
        std::array<double, 8> arr;
        ASSERT(arr.size() == ?, "Fill in the correct value.");
        ASSERT(sizeof(arr) == ?, "Fill in the correct value.");
    }
    {
        std::array<char, 21> arr{"Hello, InfiniTensor!"};
        ASSERT(arr.size() == ?, "Fill in the correct value.");
        ASSERT(sizeof(arr) == ?, "Fill in the correct value.");
        ASSERT(std::strcmp(arr.?, "Hello, InfiniTensor!") == 0, "Fill in the correct value.");
    }
    return 0;
}

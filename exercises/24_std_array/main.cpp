#include "../exercise.h"
#include <array>
#include <cstring>

// READ: std::array <https://zh.cppreference.com/w/cpp/container/array>

// TODO: 将下列 `?` 替换为正确的代码
int main(int argc, char **argv) {
    {
        //std::array<int, 5> arr{{1, 2, 3, 4, 5}};
        std::array<int, 5> arr{1, 2, 3, 4, 5};
        ASSERT(arr.size() == 5, "Fill in the correct value.");
        ASSERT(sizeof(arr) == 20, "Fill in the correct value.");
        int ans[]{1, 2, 3, 4, 5};
        ASSERT(std::memcmp(arr.data(), ans, sizeof(arr)) == 0, "Fill in the correct values.");
        //std::memcmp是比较两个指针对应的前多少字节数内容是否相同
    }
    {
        std::array<double, 8> arr;
        ASSERT(arr.size() == 8, "Fill in the correct value.");
        ASSERT(sizeof(arr) == 64, "Fill in the correct value.");
    }
    {
        std::array<char, 21> arr{"Hello, InfiniTensor!"};
        ASSERT(arr.size() == 21, "Fill in the correct value.");
        ASSERT(sizeof(arr) == 21, "Fill in the correct value.");
        ASSERT(std::strcmp(arr.data(), "Hello, InfiniTensor!") == 0, "Fill in the correct value.");
    }
    return 0;
}

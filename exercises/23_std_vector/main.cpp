#include "../exercise.h"
#include <cstring>
#include <vector>

// READ: std::vector <https://zh.cppreference.com/w/cpp/container/vector>

// TODO: 将下列 `?` 替换为正确的代码
int main(int argc, char **argv) {
    {
        std::vector<int> vec{1, 2, 3, 4, 5};
        ASSERT(vec.size() == ?, "Fill in the correct value.");
        // THINK: `std::vector` 的大小是什么意思？与什么有关？
        ASSERT(sizeof(vec) == ?, "Fill in the correct value.");
        int ans[]{1, 2, 3, 4, 5};
        ASSERT(std::memcmp(vec.?, ans, sizeof(ans)) == 0, "Fill in the correct values.");
    }
    {
        std::vector<double> vec{1, 2, 3, 4, 5};
        {
            ASSERT(vec.size() == ?, "Fill in the correct value.");
            ASSERT(sizeof(vec) == ?, "Fill in the correct value.");
            double ans[]{1, 2, 3, 4, 5};
            ASSERT(std::memcmp(vec.?, ans, sizeof(ans)) == 0, "Fill in the correct values.");
        }
        {
            vec.push_back(6);
            ASSERT(vec.size() == ?, "Fill in the correct value.");
            ASSERT(sizeof(vec) == ?, "Fill in the correct value.");
            vec.pop_back();
            ASSERT(vec.size() == ?, "Fill in the correct value.");
            ASSERT(sizeof(vec) == ?, "Fill in the correct value.");
        }
        {
            vec[4] = 6;
            ASSERT(vec[0] == ?, "Fill in the correct value.");
            ASSERT(vec[1] == ?, "Fill in the correct value.");
            ASSERT(vec[2] == ?, "Fill in the correct value.");
            ASSERT(vec[3] == ?, "Fill in the correct value.");
            ASSERT(vec[4] == ?, "Fill in the correct value.");
        }
        {
            // THINK: `std::vector` 插入删除的时间复杂度是什么？
            vec.insert(?, 1.5);
            ASSERT((vec == std::vector<double>{1, 1.5, 2, 3, 4, 6}), "Make this assertion pass.");
            vec.erase(?);
            ASSERT((vec == std::vector<double>{1, 1.5, 2, 4, 6}), "Make this assertion pass.");
        }
        {
            vec.shrink_to_fit();
            ASSERT(vec.capacity() == ?, "Fill in the correct value.");
            vec.clear();
            ASSERT(vec.empty(), "`vec` is empty now.");
            ASSERT(vec.size() == ?, "Fill in the correct value.");
            ASSERT(vec.capacity() == ?, "Fill in the correct value.");
        }
    }
    {
        std::vector<char> vec(?, ?); // TODO: 调用正确的构造函数
        ASSERT(vec[0] == 'z', "Make this assertion pass.");
        ASSERT(vec[47] == 'z', "Make this assertion pass.");
        ASSERT(vec.size() == 48, "Make this assertion pass.");
        ASSERT(sizeof(vec) == ?, "Fill in the correct value.");
        {
            auto capacity = vec.capacity();
            vec.resize(16);
            ASSERT(vec.size() == ?, "Fill in the correct value.");
            ASSERT(vec.capacity() == ?, "Fill in a correct identifier.");
        }
        {
            vec.reserve(256);
            ASSERT(vec.size() == ?, "Fill in the correct value.");
            ASSERT(vec.capacity() == ?, "Fill in the correct value.");
        }
        {
            vec.push_back('a');
            vec.push_back('b');
            vec.push_back('c');
            vec.push_back('d');
            ASSERT(vec.size() == ?, "Fill in the correct value.");
            ASSERT(vec.capacity() == ?, "Fill in the correct value.");
            ASSERT(vec[15] == ?, "Fill in the correct value.");
            ASSERT(vec[?] == 'a', "Fill in the correct value.");
            ASSERT(vec[?] == 'b', "Fill in the correct value.");
            ASSERT(vec[?] == 'c', "Fill in the correct value.");
            ASSERT(vec[?] == 'd', "Fill in the correct value.");
        }
    }

    return 0;
}

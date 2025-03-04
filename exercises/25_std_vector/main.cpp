#include "../exercise.h"
#include <cstring>
#include <vector>

// READ: std::vector <https://zh.cppreference.com/w/cpp/container/vector>

// TODO: 将下列 `?` 替换为正确的代码
int main(int argc, char **argv) {
    {
        std::vector<int> vec{1, 2, 3, 4, 5};
        ASSERT(vec.size() == 5, "Fill in the correct value.");
        // THINK: `std::vector` 的大小是什么意思？与什么有关？
        //sizeof(vec)的值通常远小于vec所管理的所有整数元素所占用的总内存大小
        ASSERT(sizeof(vec) == sizeof(std::vector<int>), "Fill in the correct value.");
        int ans[]{1, 2, 3, 4, 5};//int类型数组,sizeof(ans)是整个数组大小
        ASSERT(std::memcmp(vec.data(), ans, sizeof(ans)) == 0, "Fill in the correct values.");
    }
    {
        std::vector<double> vec{1, 2, 3, 4, 5};
        {
            ASSERT(vec.size() == 5, "Fill in the correct value.");
            ASSERT(sizeof(vec) == sizeof(std::vector<double>), "Fill in the correct value.");
            double ans[]{1, 2, 3, 4, 5};
            ASSERT(std::memcmp(vec.data(), ans, sizeof(ans)) == 0, "Fill in the correct values.");
        }
        {
            vec.push_back(6);
            ASSERT(vec.size() == 6, "Fill in the correct value.");
            ASSERT(sizeof(vec) == sizeof(std::vector<double>), "Fill in the correct value.");
            vec.pop_back();
            ASSERT(vec.size() == 5, "Fill in the correct value.");
            ASSERT(sizeof(vec) == sizeof(std::vector<double>), "Fill in the correct value.");
        }
        {
            vec[4] = 6;
            ASSERT(vec[0] == 1, "Fill in the correct value.");
            ASSERT(vec[1] == 2, "Fill in the correct value.");
            ASSERT(vec[2] == 3, "Fill in the correct value.");
            ASSERT(vec[3] == 4, "Fill in the correct value.");
            ASSERT(vec[4] == 6, "Fill in the correct value.");
        }
        {
            // THINK: `std::vector` 插入删除的时间复杂度是什么？
            vec.insert(vec.begin() + 1, 1.5);//插入一个数，一定要有vec.begin()
            ASSERT((vec == std::vector<double>{1, 1.5, 2, 3, 4, 6}), "Make this assertion pass.");
            vec.erase(vec.begin() + 3);//删除一个数
            ASSERT((vec == std::vector<double>{1, 1.5, 2, 4, 6}), "Make this assertion pass.");
        }
        {
            vec.shrink_to_fit();//在大多数标准库实现中，它通常会把 capacity() 变成 size()，释放多余内存。
            ASSERT(vec.capacity() == 5, "Fill in the correct value.");
            vec.clear();//清空 vector 的内容，但不会释放已分配的内存。size()会变成0，但是capacity()不变
            ASSERT(vec.empty(), "`vec` is empty now.");//检查 vector 是否为空，它的作用相当于：bool isEmpty = (vec.size() == 0);

            ASSERT(vec.size() == 0, "Fill in the correct value.");
            ASSERT(vec.capacity() == 5, "Fill in the correct value.");
        }
    }
    {
        std::vector<char> vec(48, 'z'); // TODO: 调用正确的构造函数
        ASSERT(vec[0] == 'z', "Make this assertion pass.");
        ASSERT(vec[47] == 'z', "Make this assertion pass.");
        ASSERT(vec.size() == 48, "Make this assertion pass.");
        ASSERT(sizeof(vec) == sizeof(std::vector<char>), "Fill in the correct value.");
        {
            auto capacity = vec.capacity();
            vec.resize(16);//用于更改 size() 的值，但 不会直接影响 capacity()。直接删除后面32个元素
            ASSERT(vec.size() == 16, "Fill in the correct value.");
            ASSERT(vec.capacity() == capacity, "Fill in a correct identifier.");
        }
        {
            //reserve(n)成员函数是用来请求改变容器的容量（capacity）至少为n，
            //即确保vector有足够的空间来存储至少n个元素，而不需要重新分配内存。
            //如果n大于当前容量，则分配新的内存空间，并将现有元素复制到新的内存位置（如果分配了新内存的话）。
            //如果n小于或等于当前容量，则reserve不做任何操作。
            vec.reserve(256);//reserve(n) 用于预分配至少 n 个元素的存储空间，但不会更改 size()。

            //如果 n > capacity()，则 capacity() 变成 n（这里 256）。否则，capacity() 会保持不变。
            //size() 不变，仍然是 16，因为 reserve() 不会创建或销毁元素。
            ASSERT(vec.size() == 16, "Fill in the correct value.");
            ASSERT(vec.capacity() == 256, "Fill in the correct value.");
        }
        {
            vec.push_back('a');
            vec.push_back('b');
            vec.push_back('c');
            vec.push_back('d');
            ASSERT(vec.size() == 20, "Fill in the correct value.");
            ASSERT(vec.capacity() == 256, "Fill in the correct value.");
            ASSERT(vec[15] == 'z', "Fill in the correct value.");
            ASSERT(vec[16] == 'a', "Fill in the correct value.");
            ASSERT(vec[17] == 'b', "Fill in the correct value.");
            ASSERT(vec[18] == 'c', "Fill in the correct value.");
            ASSERT(vec[19] == 'd', "Fill in the correct value.");
        }
    }

    return 0;
}

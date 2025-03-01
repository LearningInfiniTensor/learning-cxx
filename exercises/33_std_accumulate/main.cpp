#include "../exercise.h"
#include <numeric>

// READ: `std::accumulate` <https://zh.cppreference.com/w/cpp/algorithm/accumulate>
int mul(int a, int b){
    return a * b;
}
int main(int argc, char **argv) {
    using DataType = float;
    //std::accumulate(vec.begin(), vec.end(), init, op)
    //init是初始值，op是函数，累乘init一般是1
    int shape[]{1, 3, 224, 224};
    // TODO: 调用 `std::accumulate` 计算：
    //       - 数据类型为 float；
    //       - 形状为 shape；
    //       - 连续存储；
    //       的张量占用的字节数
    int size = sizeof(int) * std::accumulate(std::begin(shape), std::end(shape), 1, mul);
    //std::begin(shape)返回数组开始迭代器
    ASSERT(size == 602112, "4x1x3x224x224 = 602112");
    return 0;
}

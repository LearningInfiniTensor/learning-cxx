#include "../exercise.h"
#include <vector>

// 张量即多维数组。连续存储张量即逻辑结构与存储结构一致的张量。
// 通常来说，形状为 [d0, d1, ..., dn] 的张量，第 n 维是 dn 个连续的元素，第 n-1 维是 dn-1 个连续的 dn 个元素，以此类推。
// 张量的步长或跨度指的是张量每个维度上坐标 +1 时，数据指针跨过的范围。
// 因此，一个连续张量，其第 n 维的步长为 1，第 n-1 维的步长为 dn，第 n-2 维的步长为 dn*dn-1，以此类推。
// 例如，一个 2x3x4 张量，其步长为 [12, 4, 1]。

// READ: 类型别名 <https://zh.cppreference.com/w/cpp/language/type_alias>
using udim = unsigned int;

/// @brief 计算连续存储张量的步长
/// @param shape 张量的形状
/// @return 张量每维度的访问步长
std::vector<udim> strides(std::vector<udim> const &shape) {
    std::vector<udim> strides(shape.size());
    // TODO: 完成函数体，根据张量形状计算张量连续存储时的步长。
    // READ: 逆向迭代器 std::vector::rbegin <https://zh.cppreference.com/w/cpp/container/vector/rbegin>
    //       使用逆向迭代器可能可以简化代码
    return strides;
}

// ---- 不要修改以下代码 ----
int main(int argc, char **argv) {
    ASSERT((strides({2, 3, 4}) == std::vector<udim>{12, 4, 1}), "Make this assertion pass.");
    ASSERT((strides({3, 4, 5}) == std::vector<udim>{20, 5, 1}), "Make this assertion pass.");
    ASSERT((strides({1, 3, 224, 224}) == std::vector<udim>{150528, 50176, 224, 1}), "Make this assertion pass.");
    ASSERT((strides({7, 1, 1, 1, 5}) == std::vector<udim>{5, 5, 5, 5, 1}), "Make this assertion pass.");
    return 0;
}

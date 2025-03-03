#include "../exercise.h"
#include <vector>

// READ: std::vector <https://zh.cppreference.com/w/cpp/container/vector_bool>
// READ: 模板特化 <https://zh.cppreference.com/w/cpp/language/template_specialization>

// TODO: 将下列 `?` 替换为正确的代码
int main(int argc, char **argv) {
    std::vector<bool> vec(100, true);// TODO: 正确调用构造函数
    ASSERT(vec[0], "Make this assertion pass.");
    ASSERT(vec[99], "Make this assertion pass.");
    ASSERT(vec.size() == 100, "Make this assertion pass.");
    // NOTICE: 平台相关！注意 CI:Ubuntu 上的值。
    std::cout << "sizeof(std::vector<bool>) = " << sizeof(std::vector<bool>) << std::endl;
    //sizeof(vec)返回的是sizeof(std::vector<bool>)
    ASSERT(sizeof(vec) == sizeof(std::vector<bool>), "Fill in the correct value.");
    {
        vec[20] = false;
        ASSERT(~vec[20], "Fill in `vec[20]` or `!vec[20]`.");
    }
    {
        vec.push_back(false);
        ASSERT(vec.size() == 101, "Fill in the correct value.");
        ASSERT(~vec[100], "Fill in `vec[100]` or `!vec[100]`.");
    }
    {
        auto ref = vec[30];
        ASSERT(ref, "Fill in `ref` or `!ref`");
        ref = false;//大部分情况下，不管vector是什么类型的，通过auto ref = vec[i]，只要重置ref，那么对应的vec[i]元素也会产生变化
        ASSERT(~ref, "Fill in `ref` or `!ref`");
        // THINK: WHAT and WHY?这里为什么修改ref会改变vec[30]的取值
        ASSERT(vec[30], "Fill in `vec[30]` or `!vec[30]`.");
    }
    return 0;
}

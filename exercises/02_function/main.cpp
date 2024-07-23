#include "../exercise.h"

// READ: 声明 <https://zh.cppreference.com/w/cpp/language/declarations>
// NOTICE: cppreference 中的示例中指出了复杂声明的解读法，建议认真阅读。
// NOTICE: 补充由内而外读法的机翻解释 <https://learn.microsoft.com/zh-cn/cpp/c-language/interpreting-more-complex-declarators?view=msvc-170>

// TODO: 在这里声明函数

int main(int argc, char **argv) {
    ASSERT(add(123, 456) == 123 + 456, "add(123, 456) should be 123 + 456");

    auto x = 1, y = 2;
    std::cout << x << " + " << y << " = " << add(x, y) << std::endl;
    return 0;
}

int add(int a, int b) {
    // TODO: 补全函数定义，但不要移动代码行
}

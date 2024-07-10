#include "../exercise.h"

// TODO: 在这里声明函数

int main(int argc, char **argv) {
    ASSERT(add(123, 456) == 123 + 456, "add(123, 456) should be 123 + 456");

    auto x = 1, y = 2;
    std::cout << x << " + " << y << " = " << add(x, y) << std::endl;
    return 0;
}

// TODO: 补全函数定义，但不要移动代码行
// THINK: `static` 修饰函数有什么效果？
static int add(int a, int b) {
}

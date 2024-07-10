#include <cassert>
#include <iostream>

// NOTE: 这是函数声明
int add(int, int);

int main(int argc, char **argv) {
    assert(add(123, 456) == 123 + 456);

    auto x = 1, y = 2;
    std::cout << x << " + " << y << " = " << add(x, y) << std::endl;
    return 0;
}

// TODO: 补全函数定义
// THINK: `static` 修饰函数有什么效果？
static int add(int a, int b) {
    return a + b;
}

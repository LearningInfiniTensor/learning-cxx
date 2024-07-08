#include <iostream>

// NOTE: 这是函数声明
int add(int, int);

int main(int argc, char **argv) {
    auto x = 1, y = 2;
    std::cout << x << " + " << y << " = " << add(x, y) << std::endl;
    return 0;
}

// TODO: 补全函数定义
int add(int a, int b) {
    return a + b;
}

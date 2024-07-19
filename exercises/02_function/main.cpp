#include "../exercise.h"

// TODO: 在这里声明函数

int add(int x, int y);

int main(int argc, char **argv) {
    ASSERT(add(123, 456) == 123 + 456, "add(123, 456) should be 123 + 456");

    auto x = 1, y = 2;
    std::cout << x << " + " << y << " = " << add(x, y) << std::endl;
    return 0;
}

int add(int a, int b) {
    return a + b;
}

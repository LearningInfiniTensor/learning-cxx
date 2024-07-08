#include <iostream>

constexpr int fibonacci(int i) {
    switch (i) {
        case 0:
            return 0;
        case 1:
            return 1;
        default:
            return fibonacci(i - 1) + fibonacci(i - 2);
    }
}

int main(int argc, char **argv) {
    constexpr auto FIB25 = fibonacci(25);
    std::cout << "fibonacci(25) = " << FIB25 << std::endl;

    auto fib30 = fibonacci(30);
    std::cout << "fibonacci(30) = " << fib30 << std::endl;

    return 0;
}

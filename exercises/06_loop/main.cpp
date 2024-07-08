#include <iostream>

unsigned long long fibonacci(int i) {
    static unsigned long long cache[128]{0, 1}, next = 2;
    for (; next <= i; ++next) {
        cache[next] = cache[next - 1] + cache[next - 2];
    }
    return cache[i];
}

int main(int argc, char **argv) {
    auto fib100 = fibonacci(100);
    std::cout << "fibonacci(100) = " << fib100 << std::endl;
    return 0;
}

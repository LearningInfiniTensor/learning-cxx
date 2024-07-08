#include <iostream>

class Fibonacci {
    size_t cache[128];
    int next = 2;

public:
    Fibonacci() : cache{0, 1}, next(2) {}

    size_t operator[](int i) {
        for (; next <= i; ++next) {
            cache[next] = cache[next - 1] + cache[next - 2];
        }
        return cache[i];
    }

    int cached() const {
        return next;
    }
};

void use_const(Fibonacci const &fib) {
    std::cout << "cached = " << fib.cached() << std::endl;
}

int main(int argc, char **argv) {
    Fibonacci fib;
    std::cout << "fibonacci(10) = " << fib[10] << std::endl;
    use_const(fib);
    return 0;
}

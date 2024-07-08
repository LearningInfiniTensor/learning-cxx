#include <iostream>

class BoxedFibonacci {
    size_t *cache;
    int next = 2;

public:
    BoxedFibonacci()
        : cache(new size_t[128]{0, 1}), next(2) {}
    BoxedFibonacci(BoxedFibonacci const &other)
        : cache(new size_t[128]), next(other.next) {
        std::memcpy(cache, other.cache, sizeof(size_t) * next);
    }
    ~BoxedFibonacci() {
        std::cout << "Drop Fibonacci with next = " << next << std::endl;
        delete[] cache;
    }

    size_t operator[](int i) {
        for (; next <= i; ++next) {
            cache[next] = cache[next - 1] + cache[next - 2];
        }
        return cache[i];
    }
};

int main(int argc, char **argv) {
    BoxedFibonacci fib0, fib1;
    std::cout << "fibonacci(10) = " << fib0[10] << std::endl;
    std::cout << "fibonacci(100) = " << fib1[100] << std::endl;
    return 0;
}

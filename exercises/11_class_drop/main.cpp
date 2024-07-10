#include "../exercise.h"

class BoxedFibonacci {
    size_t *cache;
    int next = 2;

public:
    BoxedFibonacci() : cache(new size_t[128]{0, 1}), next(2) {}
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
    BoxedFibonacci fib;
    std::cout << "fibonacci(10) = " << fib[10] << std::endl;
    return 0;
}

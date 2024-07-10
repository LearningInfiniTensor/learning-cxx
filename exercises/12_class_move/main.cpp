#include <cassert>
#include <iostream>

class BoxedFibonacci {
    size_t *cache;
    int next = 2;

public:
    BoxedFibonacci()
        : cache(new size_t[128]{0, 1}), next(2) {}
    BoxedFibonacci(BoxedFibonacci &&other) noexcept
        : cache(std::exchange(other.cache, nullptr)),
          next(std::exchange(other.next, 0)) {
        std::cout << "Move Fibonacci with next = " << next << std::endl;
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

    bool is_available() const {
        return cache;
    }
};

int main(int argc, char **argv) {
    BoxedFibonacci fib;
    std::cout << "fibonacci(10) = " << fib[10] << std::endl;

    auto fib_ = std::move(fib);
    assert(!fib.is_available());
    assert(fib_.is_available());
    std::cout << "fibonacci(12) = " << fib_[12] << std::endl;

    return 0;
}

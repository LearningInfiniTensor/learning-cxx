#include "../exercise.h"

// READ: 左值右值（概念）<https://learn.microsoft.com/zh-cn/cpp/c-language/l-value-and-r-value-expressions?view=msvc-170>
// READ: 左值右值（细节）<https://zh.cppreference.com/w/cpp/language/value_category>
// READ: 关于移动语义 <https://learn.microsoft.com/zh-cn/cpp/cpp/rvalue-reference-declarator-amp-amp?view=msvc-170#move-semantics>
// READ: 如果实现移动构造 <https://learn.microsoft.com/zh-cn/cpp/cpp/move-constructors-and-move-assignment-operators-cpp?view=msvc-170>

// READ: 移动构造函数 <https://zh.cppreference.com/w/cpp/language/move_constructor>
// READ: 移动赋值 <https://zh.cppreference.com/w/cpp/language/move_assignment>
// READ: 运算符重载 <https://zh.cppreference.com/w/cpp/language/operators>
//移动构造器（move constructor）允许一个对象将其资源“移动”到另一个新创建的对象中，
//而不是复制这些资源。这通常用于优化性能，特别是在处理大型数据结构或动态分配的内存时。//
//移动后，源对象通常处于有效但未定义的状态，这意味着它不应该再被使用，除非它被重新初始化。
class DynFibonacci {
    size_t *cache;
    int cached;

public:
    // TODO: 实现动态设置容量的构造器
    DynFibonacci(int capacity): cache(new size_t[capacity]), cached(2) {
        cache[0] = 0;
        cache[1] = 1;
    }

    // TODO: 实现移动构造器
    DynFibonacci(DynFibonacci &&other) noexcept : cache(nullptr), cached(0){
        cache = other.cache;//将 other 的 cache 指针 赋值给当前对象，即直接接管 other 资源
        cached = other.cached;//复制 cached 记录的最大索引。

        other.cache = nullptr;//将 other 的 cache 置空，防止析构时 delete[] 重复释放。
        other.cached = 0;//重置 other.cached。
    }

    // TODO: 实现移动赋值
    // NOTICE: ⚠ 注意移动到自身问题 ⚠
    DynFibonacci &operator=(DynFibonacci &&other) noexcept {//重载赋值运算符 =,
        //noexcept声明此函数不会抛出异常（移动赋值运算符通常应该是 noexcept 以优化性能）。
        if (this != &other){//避免自我赋值（a = std::move(a) 的情况）。
            //this 是一个指针（DynFibonacci*）,other 是一个对象（DynFibonacci&&，即 DynFibonacci 类型的引用）
            //&other 取 other 的地址，使 &other 变成指针（DynFibonacci*），这样 this != &other 才能正确比较。
            delete[] cache;//先释放当前对象的 cache，防止内存泄漏。

            cache = other.cache;//转移 other 资源。
            cached = other.cached;

            other.cache = nullptr;//将 other 的 cache 置空，防止 other 被析构时释放这块内存。
            other.cached = 0;
        }
        return *this;//*this 代表当前对象的 引用（DynFibonacci&）。
    }//这样可以支持DyFibonacci a,b,c;a = std::move(b = std::move(c));

    // TODO: 实现析构器，释放缓存空间
    ~DynFibonacci(){
        delete[] cache;
    }

    // TODO: 实现正确的缓存优化斐波那契计算
    size_t operator[](int i) {//函数签名可以替换
        for (; cached < i + 1; ++cached) {
            cache[cached] = cache[cached - 1] + cache[cached - 2];
        }
        return cache[i];
    }

    // NOTICE: 不要修改这个方法
    size_t operator[](int i) const {//函数签名可以替换
        ASSERT(i <= cached, "i out of range");
        return cache[i];
    }

    // NOTICE: 不要修改这个方法
    bool is_alive() const {
        return cache;
    }//检查当前对象是否仍然持有有效的 cache 指针。
//如果对象被移动后 cache == nullptr，则返回 false。
};

int main(int argc, char **argv) {
    DynFibonacci fib(12);
    ASSERT(fib[10] == 55, "fibonacci(10) should be 55");

    DynFibonacci const fib_ = std::move(fib);//会自动调用DynFibonacci(DynFibonacci &&other) noexcept
    ASSERT(!fib.is_alive(), "Object moved");
    ASSERT(fib_[10] == 55, "fibonacci(10) should be 55");

    DynFibonacci fib0(6);
    DynFibonacci fib1(12);

    fib0 = std::move(fib1);
    fib0 = std::move(fib0);
    ASSERT(fib0[10] == 55, "fibonacci(10) should be 55");

    return 0;
}

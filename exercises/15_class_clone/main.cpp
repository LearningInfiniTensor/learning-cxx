#include "../exercise.h"

// READ: 复制构造函数 <https://zh.cppreference.com/w/cpp/language/copy_constructor>
// READ: 函数定义（显式弃置）<https://zh.cppreference.com/w/cpp/language/function>


class DynFibonacci {
    size_t *cache;
    int cached;

public:
    // TODO: 实现动态设置容量的构造器
    //构造函数使用初始化列表来分配cache数组并初始化cached成员是非常重要的
    DynFibonacci(int capacity): cache(new size_t[capacity]), cached(2) {
        cache[0] = 0;//通过构造函数Fibonacci把cache前两个初始化为0，1
        cache[1] = 1;
    }

    // TODO: 实现复制构造器
    DynFibonacci(DynFibonacci const &other): cache(other.cache), cached(other.cached) {
        //cached = other.cached;
        //cache = new size_t[cached];//最好还是申请一片新内存来存放新对象的cache
        //这种时候可能也需要额外复制析构器释放缓存空间
        for(int i = 0; i < cached; i++){//通过cache(other.cache)复制一个新的数组，通过cached(other.cached)把other的cached赋值给cached
            cache[i] = other.cache[i];
        }//此时要求第一个类必须先跑一次get函数，把cached结果更新才能保证正确性
    }

    // TODO: 实现析构器，释放缓存空间
    ~DynFibonacci(){
        delete[] cache;
    }

    // TODO: 实现正确的缓存优化斐波那契计算
    size_t get(int i) {
        for (; cached < i + 1; ++cached) {
            cache[cached] = cache[cached - 1] + cache[cached - 2];
        }
        return cache[i];
    }

    // NOTICE: 不要修改这个方法
    // NOTICE: 名字相同参数也相同，但 const 修饰不同的方法是一对重载方法，可以同时存在
    //         本质上，方法是隐藏了 this 参数的函数
    //         const 修饰作用在 this 上，因此它们实际上参数不同
    size_t get(int i) const {//这个const的存在使得这个get函数不能修改cache数组
        if (i <= cached) {
            return cache[i];
        }
        ASSERT(false, "i out of range");
    }
};

int main(int argc, char **argv) {
    DynFibonacci fib(12);
    ASSERT(fib.get(10) == 55, "fibonacci(10) should be 55");
    DynFibonacci const fib_ = fib;
    ASSERT(fib_.get(10) == fib.get(10), "Object cloned");
    return 0;
}

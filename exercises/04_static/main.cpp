#include "../exercise.h"

// READ: `static` 关键字 <https://zh.cppreference.com/w/cpp/language/storage_duration>
// THINK: 这个函数的两个 `static` 各自的作用是什么？
static int func(int param) {//这个static去掉似乎对结果没影响
    static int static_ = param;//初始化：static int static_ = param; 
    //表示 static_ 在函数第一次调用时被初始化为 param 的值。后续的函数调用中，static_ 会保留上次调用后的值，而不是重新初始化。
    // std::cout << "static_ = " << static_ << std::endl;
    return static_++;
}

int main(int argc, char **argv) {
    // TODO: 将下列 `?` 替换为正确的数字
    ASSERT(func(5) == 5, "static variable value incorrect");//static_ = param = 5, return static_, static_ = static_ + 1 = 6
    ASSERT(func(4) == 6, "static variable value incorrect");//return static_ = 6, static_c += 1
    ASSERT(func(3) == 7, "static variable value incorrect");//return static_ = 7, static_c += 1
    ASSERT(func(2) == 8, "static variable value incorrect");
    ASSERT(func(1) == 9, "static variable value incorrect");
    return 0;
}

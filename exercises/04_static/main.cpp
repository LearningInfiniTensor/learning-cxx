#include "../exercise.h"

// READ: `static` 关键字 <https://zh.cppreference.com/w/cpp/language/storage_duration>
// THINK: 这个函数的两个 `static` 各自的作用是什么？
static int func(int param) {
    static int static_ = param;
    // std::cout << "static_ = " << static_ << std::endl;
    return static_++;
}

int main(int argc, char **argv) {
    // TODO: 将下列 `?` 替换为正确的数字
    ASSERT(func(5) == ?, "static variable value incorrect");
    ASSERT(func(4) == ?, "static variable value incorrect");
    ASSERT(func(3) == ?, "static variable value incorrect");
    ASSERT(func(2) == ?, "static variable value incorrect");
    ASSERT(func(1) == ?, "static variable value incorrect");
    return 0;
}

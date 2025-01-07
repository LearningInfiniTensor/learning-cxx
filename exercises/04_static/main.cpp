#include "../exercise.h"

// READ: `static` 关键字 <https://zh.cppreference.com/w/cpp/language/storage_duration>
// THINK: 这个函数的两个 `static` 各自的作用是什么？
/*
static int func(int param) 函数定义了一个名为 func 的函数，它接收一个整数参数 param 并返回一个整数。static 关键字在这里用来修饰函数，表示这个函数只能在当前文件内被调用（即具有内部链接），这意味着其他源文件中的代码不能直接调用这个函数。

函数体内的 static int static_ = param; 定义了一个静态局部变量 static_，并初始化为传入的参数值 param。静态局部变量在整个程序运行期间都存在，但是它的作用域仅限于定义它的函数内部。重要的是，静态局部变量只会在第一次进入该函数时初始化一次，之后每次调用该函数时都会保留上次结束时的值
*/
static int func(int param) {
    static int static_ = param;
    std::cout << "static_ = " << static_ << std::endl;
    return static_++;
}

int main(int argc, char **argv) {
    // TODO: 将下列 `?` 替换为正确的数字
    ASSERT(func(5) == 5, "static variable value incorrect");
    ASSERT(func(4) == 6, "static variable value incorrect");
    ASSERT(func(3) == 7, "static variable value incorrect");
    ASSERT(func(2) == 8, "static variable value incorrect");
    ASSERT(func(1) == 9, "static variable value incorrect");
    return 0;
}

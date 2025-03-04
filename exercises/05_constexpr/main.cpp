#include "../exercise.h"
/*** 
//constexpr 限制： constexpr 函数必须在编译时能够完全求值，递归调用只要能够简洁地展开成常量表达式
constexpr unsigned long long fibonacci(int i) {
//constexpr 函数要求编译器能够在编译时就计算出所有的值，不能依赖运行时的条件或者变量
//但 switch 语句并不能完全保证这一点，因为它的每个 case 分支（尤其是递归调用）都不是常量表达式。
    switch (i) {
        case 0:
            return 0;
        case 1:
            return 1;
        default:
            return fibonacci(i - 1) + fibonacci(i - 2);
    }
//switch(i) 语句要求 i 是一个常量表达式。
//在 fibonacci(i - 1) 和 fibonacci(i - 2) 的情况下，i - 1 和 i - 2 不是常量，
//递归调用本身也不是一个常量表达式，除非这些递归能够被直接展开（即编译器可以知道每次调用的具体值）。
}
***/
// constexpr unsigned long long fibonacci(int i) {
//     if (i == 0) {
//         return 0;
//     } else if (i == 1) {
//         return 1;
//     } else {
//         return fibonacci(i - 1) + fibonacci(i - 2);
//     }//这个版本导致编译过程递归计算次数太多，超过最大限制
// }
constexpr unsigned long long fibonacci(int i) {
    if (i == 0) {
        return 0;
    } else if (i == 1) {
        return 1;
    } else {
        unsigned long long a = 0, b = 1;
        unsigned long long tmp = a + b;
        for (int j = 2; j < i; j++){
            a = b;
            b = tmp;
            tmp = a + b;
        }
        return tmp;
    }//这个版本导致编译过程递归计算次数太多，超过最大限制
}
    
int main(int argc, char **argv) {
    constexpr auto FIB20 = fibonacci(20);//constexpr要求编译的时候就能直接计算，因此编译的时候会直接把20代入
    //如果使用int i = 20;constexpr auto FIB20 = fibonacci(i);编译就会报错说编译的时候不知道i是多少
    //但是使用const int i = 20;constexpr auto FIB20 = fibonacci(i);就能正确运行
    ASSERT(FIB20 == 6765, "fibonacci(20) should be 6765");
    std::cout << "fibonacci(20) = " << FIB20 << std::endl;

    // TODO: 观察错误信息，修改一处，使代码编译运行
    // PS: 编译运行，但是不一定能算出结果……
    constexpr auto ANS_N = 90;
    constexpr auto ANS = fibonacci(ANS_N);
    std::cout << "fibonacci(" << ANS_N << ") = " << ANS << std::endl;

    return 0;
}

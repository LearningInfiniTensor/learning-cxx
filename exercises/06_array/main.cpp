#include "../exercise.h"

// READ: 数组 <https://zh.cppreference.com/w/cpp/language/array>

unsigned long long arr[90]{0, 1};
unsigned long long fibonacci(int i) {
    switch (i) {
        case 0:
            return 0;
        case 1:
            return 1;
        default:
            // TODO: 补全三目表达式缺失的部分
            return arr[i] != 0 ? arr[i] : (arr[i] = fibonacci(i - 1) + fibonacci(i - 2));
    }
}

int main(int argc, char **argv) {
    // TODO: 为此 ASSERT 填写正确的值
    ASSERT(sizeof(arr) == 720, "sizeof array is size of all its elements");
    // ---- 不要修改以下代码 ----
    ASSERT(fibonacci(2) == 1, "fibonacci(2) should be 1");
    ASSERT(fibonacci(20) == 6765, "fibonacci(20) should be 6765");
    ASSERT(fibonacci(80) == 23416728348467685, "fibonacci(80) should be 23416728348467685");
    return 0;
}

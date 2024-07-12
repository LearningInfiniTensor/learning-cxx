#include "../exercise.h"

// READ: 函数模板 <https://zh.cppreference.com/w/cpp/language/function_template>
// TODO: 将这个函数模板化
int plus(int a, int b) {
    return a + b;
}

// ---- 不要修改以下代码 ----
int main(int argc, char **argv) {
    ASSERT(plus(1, 2) == 3, "plus two int");
    ASSERT(plus(1u, 2u) == 3u, "plus two unsigned int");
    ASSERT(plus(1.f, 2.f) == 3.f, "plus two float");
    ASSERT(plus(1.0, 2.0) == 3.0, "plus two double");
    return 0;
}

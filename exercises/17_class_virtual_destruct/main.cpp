#include "../exercise.h"

// READ: 静态字段 <https://zh.cppreference.com/w/cpp/language/static>

struct A {
    // TODO: 正确初始化 `nobjs`
    static int nobjs = 0;

    A() {
        ++nobjs;
    }
    ~A() {
        --nobjs;
    }
};
struct B : public A {};

int main(int argc, char **argv) {
    ASSERT(false, "todo");
    return 0;
}

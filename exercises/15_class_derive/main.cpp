#include "../exercise.h"

// READ: 派生类 <https://zh.cppreference.com/w/cpp/language/derived_class>

// 三个类型的定义在下方，它们的关系是：B 派生自 A 并包含一个 X 类型的成员。

// ↓↓↓ 这是声明
struct X;
struct A;
struct B;
// ↑↑↑ 这是声明

int main(int argc, char **argv) {
    X x = X(1);
    A a = A(2);
    B b = B(3);

    // TODO: 补全三个类型的大小
    static_assert(sizeof(X) == ?, "There is an int in X");
    static_assert(sizeof(A) == ?, "There is an int in A");
    static_assert(sizeof(B) == ?, "B is an A with an X");

    std::cout << std::endl
              << "-------------------------" << std::endl
              << std::endl;

    // 这是不可能的，A 无法提供 B 增加的成员变量的值
    // B ba = A(4);

    // 这也是不可能的，因为 A 是 B 的一部分，就好像不可以把套娃🪆的外层放进内层里。
    A ab = B(5);// 然而这个代码可以编译和运行！
    // THINK: 观察打印出的信息，推测把大象放进冰箱分几步？
    // THINK: 这样的代码是“安全”的吗？
    // NOTICE: 真实场景中不太可能出现这样的代码

    return 0;
}

// ↓↓↓ 这是定义

struct X {
    int x;

    X(int x_) : x(x_) {
        std::cout << "X(" << x << ')' << std::endl;
    }
    X(X const &other) : x(other.x) {
        std::cout << "X(X const &) : x(" << x << ')' << std::endl;
    }
    ~X() {
        std::cout << "~X(" << x << ')' << std::endl;
    }
};
struct A {
    int a;

    A(int a_) : a(a_) {
        std::cout << "A(" << a << ')' << std::endl;
    }
    A(A const &other) : A(other.a) {
        std::cout << "A(A const &) : a(" << a << ')' << std::endl;
    }
    ~A() {
        std::cout << "~A(" << a << ')' << std::endl;
    }
};
struct B : public A {
    X x;

    B(int b) : A(1), x(b) {
        std::cout << "B(" << a << ", X(" << x.x << "))" << std::endl;
    }
    B(B const &other) : A(other.a), x(other.x) {
        std::cout << "B(B const &) : A(" << a << "), x(X(" << x.x << "))" << std::endl;
    }
    ~B() {
        std::cout << "~B(" << a << ", X(" << x.x << "))" << std::endl;
    }
};

#include "../exercise.h"

// READ: 派生类 <https://zh.cppreference.com/w/cpp/language/derived_class>

static int i = 0;

struct X {
    int x;

    X(int x_) : x(x_) {//构造函数，用x_初始化x
        std::cout << ++i << ". " << "X(" << x << ')' << std::endl;
    }
    X(X const &other) : x(other.x) {//拷贝构造函数
        std::cout << ++i << ". " << "X(X const &) : x(" << x << ')' << std::endl;
    }
    ~X() {//析构函数
        std::cout << ++i << ". " << "~X(" << x << ')' << std::endl;
    }
};
struct A {
    int a;

    A(int a_) : a(a_) {
        std::cout << ++i << ". " << "A(" << a << ')' << std::endl;
    }
    A(A const &other) : a(other.a) {
        std::cout << ++i << ". " << "A(A const &) : a(" << a << ')' << std::endl;
    }
    ~A() {
        std::cout << ++i << ". " << "~A(" << a << ')' << std::endl;
    }
};
struct B : public A {//B继承自A，因此B包含A 的成员变量a，同时B还有一个成员是结构体x，因此sizeof(B)=8
    X x;

    B(int b) : A(1), x(b) {//用b初始化结构体X，传入1初始化结构体A
        std::cout << ++i << ". " << "B(" << a << ", X(" << x.x << "))" << std::endl;
    }
    B(B const &other) : A(other.a), x(other.x) {//拷贝构造函数
        std::cout << ++i << ". " << "B(B const &) : A(" << a << "), x(X(" << x.x << "))" << std::endl;
    }
    ~B() {
        std::cout << ++i << ". " << "~B(" << a << ", X(" << x.x << "))" << std::endl;
    }
};

int main(int argc, char **argv) {
    X x = X(1); // 调用 X 的构造函数
    A a = A(2); // 调用 A 的构造函数
    B b = B(3); // 先调用 A 的构造函数（作为 B 的一部分），然后调用 X 的构造函数（作为 B 的一部分），最后调用 B 的构造函数

    // TODO: 补全三个类型的大小
    static_assert(sizeof(X) == 4, "There is an int in X");
    static_assert(sizeof(A) == 4, "There is an int in A");
    static_assert(sizeof(B) == 8, "B is an A with an X");

    i = 0;
    std::cout << std::endl
              << "-------------------------" << std::endl
              << std::endl;

    // 这是不可能的，A 无法提供 B 增加的成员变量的值
    // B ba = A(4);

    // 这也是不可能的，因为 A 是 B 的一部分，就好像不可以把套娃的外层放进内层里。
    A ab = B(5);// 然而这个代码可以编译和运行！
    // THINK: 观察打印出的信息，推测把大象放进冰箱分几步？
    // THINK: 这样的代码是“安全”的吗？
    // NOTICE: 真实场景中不太可能出现这样的代码
    //对于A ab = B(5)，要知道B里面是有A的，所以这个可以编译运行，但是会丢失B里面特有的数据
    i = 0;
    std::cout << std::endl
              << "-------------------------" << std::endl
              << std::endl;

    return 0;
}

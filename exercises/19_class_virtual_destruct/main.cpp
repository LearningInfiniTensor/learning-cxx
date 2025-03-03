#include "../exercise.h"

// READ: 静态字段 <https://zh.cppreference.com/w/cpp/language/static>
// READ: 虚析构函数 <https://zh.cppreference.com/w/cpp/language/destructor>

struct A {
    // TODO: 正确初始化静态字段
    static int num_a;//静态非const变量不允许在类内部初始化，必须在类外部int A::num_a = 0初始化
//如果num_a 有const修饰，此时可以static const int num_a = 0；但是num_a不允许修改
    A() {
        ++num_a;
    }
    ~A() {
        --num_a;
    }

    virtual char name() const {
        return 'A';
    }
};
struct B final : public A {
    // TODO: 正确初始化静态字段
    static int num_b;

    B() {
        ++num_b;
    }
    ~B() {
        --num_b;
    }

    char name() const final {
        return 'B';
    }
};
int A::num_a = 10;//必须要在全局作用域初始化，不能在某个函数里面初始化，即使是main函数也不行
int B::num_b = 5;
int main(int argc, char **argv) {
    
    auto a = new A;//初始化a调用一次构造函数，num_a += 1
    auto b = new B;//B继承自A，因此又调用一次A的构造函数，num_a += 1
    printf("%d, %d\n", A::num_a, B::num_b);
    ASSERT(A::num_a == 12, "Fill in the correct value for A::num_a");
    ASSERT(B::num_b == 6, "Fill in the correct value for B::num_b");
    ASSERT(a->name() == 'A', "Fill in the correct value for a->name()");
    ASSERT(b->name() == 'B', "Fill in the correct value for b->name()");

    delete a;
    delete b;
    printf("%d, %d\n", A::num_a, B::num_b);//B 继承自 A，所以 B 的析构函数执行完后，还会调用 A 的析构函数
    ASSERT(A::num_a == 10, "Every A was destroyed");
    ASSERT(B::num_b == 5, "Every B was destroyed");

    A *ab = new B;// 派生类指针可以随意转换为基类指针
    //调用 B 的构造函数，但 B 继承 A，所以：
//先调用 A 的构造函数（因为 B 的构造函数默认调用 A 的构造函数）。
    printf("%d, %d\n", A::num_a, B::num_b);
    ASSERT(A::num_a == 11, "Fill in the correct value for A::num_a");
    ASSERT(B::num_b == 6, "Fill in the correct value for B::num_b");
    ASSERT(ab->num_a == 11, "Fill in the correct value for ab->name()");
    ASSERT(ab->name() == 'B', "Fill in the correct value for ab->name()");

    // TODO: 基类指针无法随意转换为派生类指针，补全正确的转换语句
    B &bb = dynamic_cast<B&>(*ab);
    ASSERT(bb.name() == 'B', "Fill in the correct value for bb->name()");

    // TODO: ---- 以下代码不要修改，通过改正类定义解决编译问题 ----
    delete ab;// 通过指针可以删除指向的对象，即使是多态对象,会调用A的析构函数
    ASSERT(A::num_a == 10, "Every A was destroyed");
    ASSERT(B::num_b == 6, "Every B was destroyed");//不会调用B的析构函数

    return 0;
}

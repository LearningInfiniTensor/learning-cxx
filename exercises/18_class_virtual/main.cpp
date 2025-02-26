#include "../exercise.h"

// READ: 虚函数 <https://zh.cppreference.com/w/cpp/language/virtual>

struct A {
    virtual char virtual_name() const {
        return 'A';
    }
    char direct_name() const {
        return 'A';
    }
};
//virtual_name() 是一个虚函数。这是因为它被声明为 virtual。
//虚函数的一个主要特性是它们支持多态性（polymorphism）。
//这意味着，如果 A 被用作基类，并且派生类（derived class）重写了 virtual_name() 函数，那么通过基类指针或引用调用 virtual_name() 时，将调用派生类的版本，而不是基类的版本。
//direct_name() 是一个普通函数（也称为非虚函数）。它不支持多态性。
//无论 A 的对象是通过基类还是派生类的类型来访问，调用 direct_name() 总是执行 A 类中定义的版本。
struct B : public A {
    // READ: override <https://zh.cppreference.com/w/cpp/language/override>
    char virtual_name() const override {//override检查函数签名是否和A一致
        return 'B';
    }
    char direct_name() const {
        return 'B';
    }
};
struct C : public B {
    // READ: final <https://zh.cppreference.com/w/cpp/language/final>
    char virtual_name() const final {//final不允许后面的继承类改写virtual_name()函数
        return 'C';
    }
    char direct_name() const {
        return 'C';
    }
};
struct D : public C {
    char direct_name() const {
        return 'D';
    }
};

int main(int argc, char **argv) {
    constexpr auto MSG = "Replace '?' with its correct name.";

    A a;
    B b;
    C c;
    D d;

    ASSERT(a.virtual_name() == 'A', MSG);
    ASSERT(b.virtual_name() == 'B', MSG);
    ASSERT(c.virtual_name() == 'C', MSG);
    ASSERT(d.virtual_name() == 'C', MSG);
    ASSERT(a.direct_name() == 'A', MSG);
    ASSERT(b.direct_name() == 'B', MSG);
    ASSERT(c.direct_name() == 'C', MSG);
    ASSERT(d.direct_name() == 'D', MSG);

    A &rab = b;
    B &rbc = c;
    C &rcd = d;

    ASSERT(rab.virtual_name() == '?', MSG);
    ASSERT(rbc.virtual_name() == '?', MSG);
    ASSERT(rcd.virtual_name() == '?', MSG);
    ASSERT(rab.direct_name() == '?', MSG);
    ASSERT(rbc.direct_name() == '?', MSG);
    ASSERT(rcd.direct_name() == '?', MSG);

    A &rac = c;
    B &rbd = d;

    ASSERT(rac.virtual_name() == '?', MSG);
    ASSERT(rbd.virtual_name() == '?', MSG);
    ASSERT(rac.direct_name() == '?', MSG);
    ASSERT(rbd.direct_name() == '?', MSG);

    A &rad = d;

    ASSERT(rad.virtual_name() == '?', MSG);
    ASSERT(rad.direct_name() == '?', MSG);

    return 0;
}

// READ: 扩展阅读-纯虚、抽象 <https://zh.cppreference.com/w/cpp/language/abstract_class>
// READ: 扩展阅读-虚继承 <https://zh.cppreference.com/w/cpp/language/derived_class>

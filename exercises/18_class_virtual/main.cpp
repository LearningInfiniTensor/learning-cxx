#include "../exercise.h"

// READ: 虚函数 <https://zh.cppreference.com/w/cpp/language/virtual>

struct A {
    virtual char virtual_name() const {//virtual保证这个函数在后面的派生类里面可以重写
        return 'A';//const保证这个成员函数不会修改对象（虽然这个结构体没有成员变量）
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
    char direct_name() const {//其实direct_name()可以不用额外定义，这个时候B b,b.direct_name()会自动调用A的direct_name()
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

    A &rab = b;//创建了一个A类型的rab，初始化为b,由于B是从A继承过来的，这么做合法，但是rab只能访问A的成员，不能访问B的特有成员
    B &rbc = c;
    C &rcd = d;

    ASSERT(rab.virtual_name() == 'B', MSG);//由于virtual_name是虚函数，在B被重写了，所以这里会调用B的重写版本
    ASSERT(rbc.virtual_name() == 'C', MSG);
    ASSERT(rcd.virtual_name() == 'C', MSG);//虽然virtual)name是虚函数，但是在C的时候已经被禁止重写了，所以这里还是返回C
    ASSERT(rab.direct_name() == 'A', MSG);//direct_name不是虚函数，只能调用A
    ASSERT(rbc.direct_name() == 'B', MSG);//虽然direct_name不是虚函数，但是在B里面也被重写了，所以这里会调用B的direct_name
    ASSERT(rcd.direct_name() == 'C', MSG);

    A &rac = c;//这种做法其实和上面的A &rab = b差别不大
    B &rbd = d;

    ASSERT(rac.virtual_name() == 'C', MSG);
    ASSERT(rbd.virtual_name() == 'C', MSG);
    ASSERT(rac.direct_name() == 'A', MSG);
    ASSERT(rbd.direct_name() == 'B', MSG);

    A &rad = d;

    ASSERT(rad.virtual_name() == 'C', MSG);
    ASSERT(rad.direct_name() == 'A', MSG);

    return 0;
}

// READ: 扩展阅读-纯虚、抽象 <https://zh.cppreference.com/w/cpp/language/abstract_class>
// READ: 扩展阅读-虚继承 <https://zh.cppreference.com/w/cpp/language/derived_class>

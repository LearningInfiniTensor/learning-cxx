#include "../exercise.h"

struct A {
    virtual char virtual_name() const {
        return 'A';
    }
    char direct_name() const {
        return 'A';
    }
};
struct B : public A {
    char virtual_name() const override {
        return 'B';
    }
    char direct_name() const {
        return 'B';
    }
};
struct C : public B {
    char virtual_name() const final {
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

    ASSERT(a.virtual_name() == '?', MSG);
    ASSERT(b.virtual_name() == '?', MSG);
    ASSERT(c.virtual_name() == '?', MSG);
    ASSERT(d.virtual_name() == '?', MSG);
    ASSERT(a.direct_name() == '?', MSG);
    ASSERT(b.direct_name() == '?', MSG);
    ASSERT(c.direct_name() == '?', MSG);
    ASSERT(d.direct_name() == '?', MSG);

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

#ifndef __EXERCISE_H__
#define __EXERCISE_H__

#include <iostream>

template<class T>
struct Colorful {
    int color;
    T value;
};

template<class T>
inline std::ostream &operator<<(std::ostream &os, Colorful<T> const &cf) {
    return os << "\x1b[" << cf.color << 'm' << cf.value << "\x1b[0m";
}

#define COLORFUL(VALUE, NAME)                   \
    template<class T>                           \
    inline Colorful<T> NAME(T &&val) {          \
        return {(VALUE), std::forward<T>(val)}; \
    }

COLORFUL(31, red)
COLORFUL(32, green)
COLORFUL(33, yellow)
COLORFUL(34, blue)

#undef COLORFUL

#define ASSERT(COND, MSG)                                   \
    if (!(COND)) {                                          \
        std::cerr << red("Assertion failed: ") << std::endl \
                  << std::endl                              \
                  << #COND << std::endl                     \
                  << std::endl                              \
                  << green("Message:") << std::endl         \
                  << std::endl                              \
                  << MSG << std::endl                       \
                  << std::endl;                             \
        exit(1);                                            \
    }


#endif// __EXERCISE_H__

#ifndef __EXERCISE_H__
#define __EXERCISE_H__

#include <iostream>

#define ASSERT(COND, MSG)                                                                         \
    if (!(COND)) {                                                                                \
        std::cerr << "\x1b[31mAssertion failed at line #" << __LINE__ << ": \x1b[0m" << std::endl \
                  << std::endl                                                                    \
                  << #COND << std::endl                                                           \
                  << std::endl                                                                    \
                  << "\x1b[34mMessage:\x1b[0m" << std::endl                                       \
                  << std::endl                                                                    \
                  << MSG << std::endl                                                             \
                  << std::endl;                                                                   \
        exit(1);                                                                                  \
    }

#endif// __EXERCISE_H__

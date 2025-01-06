#include "../exercise.h"

// READ: <https://stackoverflow.com/questions/156767/whats-the-difference-between-an-argument-and-a-parameter>
// THINK: 参数都有哪些传递方式？如何选择传递方式？

void func(int);

// TODO: 为下列 ASSERT 填写正确的值
int main(int argc, char **argv) {
    auto arg = 99;
    ASSERT(arg == 99, "arg should be 99");
    std::cout << "befor func call: " << arg << std::endl;
    func(arg);
    ASSERT(arg == 99, "arg should be 99");
    std::cout << "after func call: " << arg << std::endl;
    return 0;
}

// TODO: 为下列 ASSERT 填写正确的值
void func(int param) {
    ASSERT(param == 99, "param should be 99");
    std::cout << "befor add: " << param << std::endl;
    param += 1;
    ASSERT(param == 100, "param should be 100");
    std::cout << "after add: " << param << std::endl;
}

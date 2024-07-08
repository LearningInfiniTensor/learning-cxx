// See <https://stackoverflow.com/questions/156767/whats-the-difference-between-an-argument-and-a-parameter>.

#include <iostream>

void func(int param) {
    std::cout << "befor add: " << param << std::endl;
    param += 1;
    std::cout << "after add: " << param << std::endl;
}

int main(int argc, char **argv) {
    auto arg = 99;
    std::cout << "befor func call: " << arg << std::endl;
    func(arg);
    std::cout << "after func call: " << arg << std::endl;
    return 0;
}

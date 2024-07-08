// See <https://stackoverflow.com/questions/156767/whats-the-difference-between-an-argument-and-a-parameter>.

#include <iostream>

void func(int param) {
    static int static_ = param;
    std::cout << "static_ = " << static_++ << std::endl;
}

int main(int argc, char **argv) {
    func(5);
    func(4);
    func(3);
    func(2);
    func(1);
    return 0;
}

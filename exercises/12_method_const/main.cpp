#include "../exercise.h"

// READ: 有 cv 限定符的成员函数 <https://zh.cppreference.com/w/cpp/language/member_functions>

struct Fibonacci {
    int numbers[11];
    // TODO: 修改方法签名和实现，使测试通过
    //注意后面的FIB初始化为constexpr类型，因此成员函数必须是常量，表现形式为int get (int i) const{}
    //千万不要写成const int get(int i){}
    //int get (int i) const{}不能改变修改对象状态，即不能改变numbers元素，并且可以被常量对象调用，也就是被constexpr修饰的FIB
    int get(int i) const{
        if (i < 11){
            return numbers[i];
        }
        
    }
    //也就是说constexpr修饰以后，numbers数组只读，不可修改
    //用const 代替constexpr也可
};

int main(int argc, char **argv) {
    Fibonacci constexpr FIB{{0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55}};
    ASSERT(FIB.get(10) == 55, "fibonacci(10) should be 55");
    std::cout << "fibonacci(10) = " << FIB.get(10) << std::endl;
    return 0;
}

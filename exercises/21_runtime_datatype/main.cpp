#include "../exercise.h"
#include <cmath>

enum class DataType {
    Float,
    Double,
};//定义一个枚举类，通过DataType::Float访问，比如说DataType my = DataType::Float

/// @brief Tagged union 即标签化联合体，是联合体的一种常见应用。
///        Rust enum 在实现上就是标签化联合体。
struct TaggedUnion {
    DataType type;//通过这个来确定联合体union到底存储的元素是float还是double
    // NOTICE: struct/union 可以相互任意嵌套。
    union {
        float f;
        double d;
    };
    //这个联合体没有名字（它是匿名的），并且包含两个成员：float f; 和 double d;。
    //由于它是一个联合体，所以它的所有成员共享同一块内存空间。在任何给定时间，联合体只能有效存储其成员之一的值；
    //其他成员的值是未定义的（在读取时可能会导致垃圾值）。
};

// TODO: 将这个函数模板化用于 sigmoid_dyn
template<typename T>
T sigmoid(T x) {
    return 1 / (1 + std::exp(-x));
}

TaggedUnion sigmoid_dyn(TaggedUnion x) {
    TaggedUnion ans{x.type};
    // TODO: 根据 type 调用 sigmoid
    if (x.type == DataType::Float){
        ans.f = sigmoid<float>(x.f);
    }
    else if(x.type == DataType::Double){
        ans.d = sigmoid<double>(x.d);
    }
    return ans;
}

// ---- 不要修改以下代码 ----
int main(int argc, char **argv) {
    TaggedUnion xf{DataType::Float};
    xf.f = 5.f;
    auto yf = sigmoid_dyn(xf);
    ASSERT(yf.type == DataType::Float, "type mismatch");
    ASSERT(yf.f == 1 / (1 + std::exp(-5.f)), "sigmoid float");

    TaggedUnion xd{DataType::Double};
    xd.d = 5.0;
    auto yd = sigmoid_dyn(xd);
    ASSERT(yd.type == DataType::Double, "type mismatch");
    ASSERT(yd.d == 1 / (1 + std::exp(-5.0)), "sigmoid double");
    return 0;
}

#include "../exercise.h"
#include <cstring>

// READ: 类模板 <https://zh.cppreference.com/w/cpp/language/class_template>

template<class T>
struct Tensor4D {
    unsigned int shape[4];
    T *data;

    Tensor4D(unsigned int const shape_[4], T const *data_) {
        unsigned int size = 1;
        // TODO: 填入正确的 shape 并计算 size
        for (unsigned i = 0; i < 4; i++) {
            size *= shape_[i];
            shape[i] = shape_[i];
        }
        data = new T[size];
        std::memcpy(data, data_, size * sizeof(T));
    }
    ~Tensor4D() {
        delete[] data;
    }

    // 为了保持简单，禁止复制和移动
    Tensor4D(Tensor4D const &) = delete;
    Tensor4D(Tensor4D &&) noexcept = delete;

    // 这个加法需要支持“单向广播”。
    // 具体来说，`others` 可以具有与 `this` 不同的形状，形状不同的维度长度必须为 1。
    // `others` 长度为 1 但 `this` 长度不为 1 的维度将发生广播计算。
    // 例如，`this` 形状为 `[1, 2, 3, 4]`，`others` 形状为 `[1, 2, 1, 4]`，
    // 则 `this` 与 `others` 相加时，3 个形状为 `[1, 2, 1, 4]` 的子张量各自与 `others` 对应项相加。
    Tensor4D &operator+=(Tensor4D const &others) {
        // TODO: 实现单向广播的加法
        constexpr unsigned DIM = 4;
        unsigned size = 1;
        bool need2Bcst[DIM]{false};
        for (unsigned i = 0; i < DIM; i++) {
            size *= shape[i];
            if (shape[i] != others.shape[i] && others.shape[i] != 1) {
                ASSERT(false, "Unable to broadcast.")
            } else {
                need2Bcst[i] = shape[i] != others.shape[i];
            }
        }

        unsigned index[DIM]{0};
        for (unsigned i = 0; i < size; i++) {
            unsigned others_i = 0;
            for (unsigned j = 0; j < DIM; j++) {
                auto others_index = need2Bcst[j] ? 0 : index[j];
                others_i = others_i * others.shape[j] + others_index;
            }
            data[i] += others.data[others_i];
            index[DIM - 1] += 1;
            for (unsigned j = DIM - 1; index[j] == shape[j] && j >= 1; j--) {
                index[j] = 0;
                index[j - 1] += 1;
            }
        }

        return *this;
    }
};

// ---- 不要修改以下代码 ----
int main(int argc, char **argv) {
    {
        unsigned int shape[]{1, 2, 3, 4};
        // clang-format off
        int data[]{
             1,  2,  3,  4,
             5,  6,  7,  8,
             9, 10, 11, 12,

            13, 14, 15, 16,
            17, 18, 19, 20,
            21, 22, 23, 24};
        // clang-format on
        auto t0 = Tensor4D<int>(shape, data);
        auto t1 = Tensor4D<int>(shape, data);
        t0 += t1;
        for (unsigned int i = 0; i < sizeof(data) / sizeof(int); i++) {
            ASSERT(t0.data[i] == data[i] * 2, "Tensor doubled by plus its self.");
        }
    }
    {
        unsigned int s0[]{1, 2, 3, 4};
        // clang-format off
        float d0[]{
            1, 1, 1, 1,
            2, 2, 2, 2,
            3, 3, 3, 3,

            4, 4, 4, 4,
            5, 5, 5, 5,
            6, 6, 6, 6};
        // clang-format on
        unsigned int s1[]{1, 2, 3, 1};
        // clang-format off
        float d1[]{
            6,
            5,
            4,

            3,
            2,
            1};
        // clang-format on

        auto t0 = Tensor4D<float>(s0, d0);
        auto t1 = Tensor4D<float>(s1, d1);
        t0 += t1;
        for (unsigned int i = 0; i < sizeof(d0) / sizeof(float); i++) {
            ASSERT(t0.data[i] == 7.f, "Every element of t0 should be 7 after adding t1 to it.");
        }
    }
    {
        unsigned int s0[]{1, 2, 3, 4};
        // clang-format off
        double d0[]{
             1,  2,  3,  4,
             5,  6,  7,  8,
             9, 10, 11, 12,

            13, 14, 15, 16,
            17, 18, 19, 20,
            21, 22, 23, 24};
        // clang-format on
        unsigned int s1[]{1, 1, 1, 1};
        double d1[]{1};

        auto t0 = Tensor4D<double>(s0, d0);
        auto t1 = Tensor4D<double>(s1, d1);
        t0 += t1;
        for (unsigned int i = 0; i < sizeof(d0) / sizeof(double); i++) {
            ASSERT(t0.data[i] == d0[i] + 1, "Every element of t0 should be incremented by 1 after adding t1 to it.");
        }
    }
}

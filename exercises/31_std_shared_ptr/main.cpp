#include "../exercise.h"
#include <memory>

// READ: `std::shared_ptr` <https://zh.cppreference.com/w/cpp/memory/shared_ptr>
// READ: `std::weak_ptr` <https://zh.cppreference.com/w/cpp/memory/weak_ptr>

// TODO: 将下列 `?` 替换为正确的值
int main(int argc, char **argv) {
    auto shared = std::make_shared<int>(10);
    std::shared_ptr<int> ptrs[]{shared, shared, shared};

    std::weak_ptr<int> observer = shared;
    ASSERT(observer.use_count() == ?, "");

    ptrs[0].reset();
    ASSERT(observer.use_count() == ?, "");

    ptrs[1] = nullptr;
    ASSERT(observer.use_count() == ?, "");

    ptrs[2] = std::make_shared<int>(*shared);
    ASSERT(observer.use_count() == ?, "");

    ptrs[0] = shared;
    ptrs[1] = shared;
    ptrs[2] = std::move(shared);
    ASSERT(observer.use_count() == ?, "");

    std::ignore = std::move(ptrs[0]);
    ptrs[1] = std::move(ptrs[1]);
    ptrs[1] = std::move(ptrs[2]);
    ASSERT(observer.use_count() == ?, "");

    shared = observer.lock();
    ASSERT(observer.use_count() == ?, "");

    shared = nullptr;
    for (auto &ptr : ptrs) ptr = nullptr;
    ASSERT(observer.use_count() == ?, "");

    shared = observer.lock();
    ASSERT(observer.use_count() == ?, "");

    return 0;
}

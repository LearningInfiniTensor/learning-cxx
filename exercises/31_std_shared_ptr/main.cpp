#include "../exercise.h"
#include <memory>

// READ: `std::shared_ptr` <https://zh.cppreference.com/w/cpp/memory/shared_ptr>
// READ: `std::weak_ptr` <https://zh.cppreference.com/w/cpp/memory/weak_ptr>

// TODO: 将下列 `?` 替换为正确的值
int main(int argc, char **argv) {
    //std::make_shared是一个用于创建 std::shared_ptr 的工厂函数。在这段代码中，
    auto shared = std::make_shared<int>(10);//创建了一个指向 int 类型的智能指针，指向的 int 值为 10。
    //它返回一个 std::shared_ptr<int> 类型的对象，并且内部管理这个内存
    std::shared_ptr<int> ptrs[]{shared, shared, shared};
    //使用 std::make_shared 来创建 shared_ptr 比直接使用 new 和 shared_ptr 的构造函数更高效。
    //它通过一个单独的内存分配同时分配了 shared_ptr 和它管理的对象，避免了额外的内存分配，通常能提升性能并减少内存碎片。
    //shared_ptr 是一种引用计数的智能指针，它会在多个 shared_ptr 对象指向同一个资源时管理这个资源的生命周期。
    //每次拷贝或赋值一个 shared_ptr 时，引用计数都会增加。只有在引用计数为零时（即没有 shared_ptr 再指向该对象时），对象才会被销毁。
    std::weak_ptr<int> observer = shared;//td::weak_ptr 是另一种智能指针，它不会增加引用计数，因此不会影响资源的生命周期。它主要用于观察 shared_ptr 管理的对象，但不干预对象的销毁。
    ASSERT(observer.use_count() == 4, "");//数组3次+第一次
    //use_count() 函数返回当前 shared_ptr 管理的对象的引用计数

    ptrs[0].reset();//reset() 方法会释放 ptrs[0] 持有的对象的所有权，并将其指针置为 nullptr。
    ASSERT(observer.use_count() == 3, "");

    ptrs[1] = nullptr;//ptrs[1] = nullptr 会将 ptrs[1] 置为 nullptr，意味着 ptrs[1] 不再指向原先的 int(10)。执行后，ptrs[1] 被解除关联，不再持有该对象。
    ASSERT(observer.use_count() == 2, "");

    ptrs[2] = std::make_shared<int>(*shared);// 创建了一个新的 shared_ptr<int>，它指向 shared 所管理的对象（即值为 10 的 int）。注意到，这里并没有改变 shared 或原对象的生命周期，只是创建了一个新的 shared_ptr<int>，因此引用计数会增加
    ASSERT(observer.use_count() == 1, "");//ptrs[2]不指向原来的shared，而是指向一个新对象，虽然这个新对象内容和shared一样

    ptrs[0] = shared;
    ptrs[1] = shared;
    ptrs[2] = std::move(shared);//std::move(shared) 将 shared 的所有权转移给 ptrs[2]。shared 现在指向 nullptr，而 ptrs[2] 拥有这个对象的所有权。
    //上面这个ptrs[2] = std::move(shared)导致ptrs[2]的计数+1，但是原来的shared计数使用的ptrs[0],ptrs[1]不受影响
    ASSERT(observer.use_count() == 3, "");

    std::ignore = std::move(ptrs[0]);//std::move(ptrs[0]) 将 ptrs[0] 的所有权转移，ptrs[0] 不再指向对象。此时没有任何 shared_ptr 对象再指向该对象，
    ptrs[1] = std::move(ptrs[1]);//将 ptrs[1] 的所有权转移，ptrs[1] 不再指向该对象。
    ptrs[1] = std::move(ptrs[2]);//将 ptrs[2] 的所有权转移，ptrs[1] 现在持有该对象，而 ptrs[2] 不再持有它。
    ASSERT(observer.use_count() == 2, "");

    shared = observer.lock();//observer.lock() 尝试将 observer 转换为 shared_ptr。由于之前 ptrs[0]、ptrs[1] 和 ptrs[2] 都不再持有该对象，因此 observer.lock() 返回一个空的 shared_ptr（即 nullptr）。
    //由于shared仍然存在，lock返回一个新的shared_ptr实例（locked_ptr），它指向与shared相同的对象
    ASSERT(observer.use_count() == 3, "");

    shared = nullptr;
    for (auto &ptr : ptrs) ptr = nullptr;
    ASSERT(observer.use_count() == 0, "");

    shared = observer.lock();
    ASSERT(observer.use_count() == 0, "");

    return 0;
}

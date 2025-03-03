#include "../exercise.h"
#include <cstring>
#include <memory>
#include <string>
#include <vector>

// READ: `std::unique_ptr` <https://zh.cppreference.com/w/cpp/memory/unique_ptr>

std::vector<std::string> RECORDS;

class Resource {
    std::string _records;

public:
    void record(char record) {
        _records.push_back(record);
    }

    ~Resource() {//在 C++ 中，对象的析构顺序通常是后进先出（LIFO），特别是当涉及到局部变量或临时对象时。
        std::cout << "Destroying Resource with _records = " << _records << std::endl;
        RECORDS.push_back(_records);
    }
};

using Unique = std::unique_ptr<Resource>;
//Unique 是 std::unique_ptr<Resource> 的类型别名。
//std::unique_ptr 是一个智能指针，确保资源的唯一所有权，也就是只能有一个 unique_ptr 指向某个 Resource 对象。
//std::unique_ptr 的对象在超出作用域时会自动销毁，释放资源。
Unique reset(Unique ptr) {//接收一个 std::unique_ptr<Resource>（即 Unique 类型的参数 ptr）
    if (ptr) ptr->record('r');//ptr 不为空（即它指向一个有效的 Resource 对象），它会调用 ptr->record('r')，向 Resource 对象添加记录 'r'
    return std::make_unique<Resource>();
    //创建一个新的 Resource 对象并返回它。原来的 ptr 会被丢弃（因为 std::unique_ptr 是唯一拥有权的，原来的指针不能再访问这个对象）
}
//std::make_unique的作用是创建一个对象，并返回一个管理它的 std::unique_ptr，避免手动使用 new
//std::unique_ptr<int> ptr = std::make_unique<int>(42);

Unique drop(Unique ptr) {
    if (ptr) ptr->record('d');
    return nullptr;
}
Unique forward(Unique ptr) {
    if (ptr) ptr->record('f');
    return ptr;
}

int main(int argc, char **argv) {
    std::vector<std::string> problems[3];
    //注意reset(nullptr)返回std::make_unique<Resource>();虽然没有传入什么，但是此时已经有_record = ""，此时就不是空指针了
    drop(forward(reset(nullptr)));
    problems[0] = std::move(RECORDS);//std::move(RECORDS) 会清空 RECORDS

    forward(drop(reset(forward(forward(reset(nullptr))))));//reset会释放原来的resource，返回一个新的resource，此时会有断点
    problems[1] = std::move(RECORDS);

    drop(drop(reset(drop(reset(reset(nullptr))))));
    problems[2] = std::move(RECORDS);

    // ---- 不要修改以上代码 ----

    std::vector<const char *> answers[]{
        {"fd"},
        // TODO: 分析 problems[1] 中资源的生命周期，将记录填入 `std::vector`
        // NOTICE: 此题结果依赖对象析构逻辑，平台相关，提交时以 CI 实际运行平台为准
        {"d", "ffr"},
        {"d", "d", "r"},
    };

    // ---- 不要修改以下代码 ----

    for (auto i = 0; i < 3; ++i) {
        ASSERT(problems[i].size() == answers[i].size(), "wrong size");
        for (auto j = 0; j < problems[i].size(); ++j) {
            //std::cout << problems[i][j].c_str() << "," << answers[i][j] << std::endl;
            ASSERT(std::strcmp(problems[i][j].c_str(), answers[i][j]) == 0, "wrong location");
        }
    }

    return 0;
}

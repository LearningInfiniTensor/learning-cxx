# Learning C++

> **NOTICE** 推荐阅读 [C++ 参考手册](https://zh.cppreference.com/w/cpp) 学习 C/C++ 语法和 STL 库。

## 使用指南

1. 安装构建工具 [xmake](https://xmake.io/)

   xmake 是跨平台的 C/C++ 构建系统，具有安装方便，配置简洁的优点。

   安装方式见[中文官方文档](https://xmake.io/#/zh-cn/getting_started?id=%e5%ae%89%e8%a3%85)。

   > **NOTICE** xmake 仅是构建工具，不包括工具链。仍需先安装 C/C++ 工具链（MSVC、GCC 或 Clang）才能开始使用项目。

   > **NOTICE** 有报告称 xmake 在 Windows 上存在定位工具链失败的问题。因此推荐按下列规则选择学习平台：
   >
   > 1. 如果已经在默认位置安装 Visual Studio/Ms C++ Build Tools，则推荐原生 Windows 学习本项目；
   > 2. 如果已经配置好 WSL2，则推荐 WSL2 + GCC/Clang 学习本项目；
   > 3. 如果未配置过任何工具链，则推荐在默认位置安装 Visual Studio；
   > 4. 不推荐 MinGW 或 Cygwin，除非足够熟悉这些环境，可以自行完成配置；

   > **NOTICE** 如果仍遇到工具链问题，推荐浏览 [xmake issues](https://github.com/xmake-io/xmake/issues)；

2. 克隆仓库

   ```shell
   git clone https://github.com/LearningInfiniTensor/learning-cxx.git
   ```

3. 编译学习系统

   ```shell
   cd learning-cxx
   xmake
   ```

4. 开始学习

   使用

   ```shell
   xmake run learn <exercise number>
   ```

   运行指定练习，例如：

   ```shell
   xmake run learn 0
   ```

   运行 0 号练习。

5. 总结学习

   使用

   ```shell
   xmake run summary
   ```

   总结所有练习通过情况。

## 其他学习资源

- [Microsoft：欢迎回到 C++](https://learn.microsoft.com/zh-cn/cpp/cpp/welcome-back-to-cpp-modern-cpp?view=msvc-170)
- [C++ Core Guidelines](https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines)
- ~~[Google 风格指南（中文版）](https://zh-google-styleguide.readthedocs.io/en/latest/google-cpp-styleguide/contents.html)~~（deprecated）
- [360 安全规则集合](https://github.com/Qihoo360/safe-rules)

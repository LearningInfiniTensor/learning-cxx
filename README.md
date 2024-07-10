# Learning C++

## 使用指南

1. 安装构建工具 [xmake](https://xmake.io/)

   xmake 是跨平台的 C/C++ 构建系统，具有安装方便，配置简洁的优点。

   安装方式见[中文官方文档](https://xmake.io/#/zh-cn/getting_started?id=%e5%ae%89%e8%a3%85)。

   > **NOTICE** xmake 仅是构建工具，不包括工具链。仍需先安装 C/C++ 工具链（MSVC、GCC 或 Clang）才能开始使用项目。

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

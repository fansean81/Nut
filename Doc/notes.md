
## 动态链接库
### Linux下的定义
#### 在CMake中定义
    'add_library(nut SHARED ${NUT_SOURCES})'
- SHARED 关键字指定生成共享库
- 在 Linux 上生成 .so 文件, .so 文件是 共享对象文件（Shared Object），这是 Linux/Unix 系统中的动态链接库文件
#### 在头文件中定义
    ‘#define NUT_API __attribute__((visibility("default")))’
- __attribute__((visibility("default"))) 是GCC/Clang编译器的特性
- 作用：标记符号（函数、类等）为"可见"，允许从动态库外部访问
- 在Linux/Unix系统中，**默认情况下动态库的符号是隐藏的，需要显式标记为可见**
#### 使用方法
    ‘target_link_libraries(sandbox PRIVATE nut)’

### Windows下的定义
1. __declspec(dllexport)
作用：标记符号（函数、类、变量）为导出符号
使用时机：在构建 DLL 时使用
效果：告诉编译器这个符号需要被导出，其他程序可以调用
2. __declspec(dllimport)
作用：标记符号为导入符号
使用时机：在使用 DLL 的程序中（客户端）使用
效果：告诉编译器这个符号来自外部 DLL，需要动态链接

## C/C++点滴知识
### 局命名空间解析符（::）
    ‘::Nut::Log::GetCoreLogger()‘
- 第一个 :: 表示从全局命名空间开始，它的作用是
    - 确保从全局命名空间开始查找
    - 避免任何可能的命名冲突
    - 提高代码的明确性和可维护性
- 后面的 :: 是命名空间和类的成员访问符

### 同时使用inline和static关键字
    ‘’‘class Log {
    public:
        inline static spdlog::logger& GetCoreLogger() { return s_CoreLogger; }
        inline static spdlog::logger& GetClientLogger() { return s_ClientLogger; }
    };
- static（静态成员函数）
    - 作用域：属于类本身，而不是类的实例
    - 调用方式：Log::GetCoreLogger()（无需创建Log对象）
    - 内存分配：在程序生命周期内只存在一份
    - 访问权限：只能访问静态成员变量
- inline（内联函数）
    - 编译优化：建议编译器将函数体直接插入调用处
    - 减少开销：避免函数调用的栈帧创建和跳转
    - 适用场景：简单、短小的函数
- inline static的组合提供了以下优势：
    - 最佳性能（零开销抽象）
    - 简洁接口（直接类名调用）
    - 易于维护（头文件中完整定义）
    - 符合C++最佳实践

### std::shared_ptr
- 作用：智能指针，用于管理动态分配的对象，自动处理内存释放
- 原理：基于引用计数，多个智能指针可以共享同一个对象，当最后一个指针销毁时，对象才会被释放
- 优势：
    - 避免内存泄漏
    - 自动管理对象生命周期
    - 支持自定义删除器（如释放资源、关闭文件等）
- 适用场景：
    - 动态分配的对象需要被多个部分共享
    - 不确定对象生命周期的情况
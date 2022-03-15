# \[WIP\] Base64 编码/解码（C++ 实现）

by: 韩琦 / rhanqtl

## 目录结构

- `include/` 包含库的头文件
- `src/` 是库的 cpp 代码，
- `tests/` 是单元测试代码
- `lib/` 是依赖库的代码
- `oj/` 是 C++ 考试平台上可以运行的代码

## 依赖

- Git
  - 需要克隆作为 sub-module 的 GoogleTest
- 支持 C++11 的 C++ 编译器
- CMake 3.10+

## 构建

在项目根目录下：

```
$ mkdir build && cd build
$ cmake ..
$ cmake --build . --target all
```

成功后可以在 `build/tests` 目录下找到 `base64_encode_test` 和 `base64_decode_test`


## 使用示例

见 https://github.com/rhanqtl/base64-cpp-example
# \[WIP\] Base64 编码/解码（C++ 实现）

by: 韩琦 / rhanqtl

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

成功后可以在 `build/tests` 目录下找到 `Base64_encode_test` 和 `Base64_decode_test`

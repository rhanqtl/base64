# 必要的，两个参数分别是项目名和项目使用的编程语言，C++ 用 CXX 代替
# 项目名可以通过 CMAKE_PROJECT_NAME 引用
PROJECT(Base64 CXX)

CMAKE_MINIMUM_REQUIRED(VERSION 3.10)

SET(CMAKE_CXX_STANDARD 11)

SET(ENCODE_LIB_NAME base64_encode_lib)
SET(ENCODE_TEST_NAME base64_encode_test)
SET(DECODE_LIB_NAME base64_decode_lib)
SET(DECODE_TEST_NAME base64_decode_test)

ADD_SUBDIRECTORY(src)

OPTION(WITH_UNIT_TESTS "whether or not to build unit tests" OFF)

IF (WITH_UNIT_TESTS)
    ADD_SUBDIRECTORY(tests)
    ADD_SUBDIRECTORY(lib/googletest)
ENDIF ()

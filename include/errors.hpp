#ifndef BASE64_ERRORS_H
#define BASE64_ERRORS_H

#include <cstdint>

namespace base64 {

enum class ErrCode {
  Success = 0,
  NoEnoughChars = 1,
  InvalidChar = 2,
};

class BaseError {
 public:
  virtual ErrCode type() = 0;
};

class Success : public BaseError {
 public:
  ErrCode type() override { return ErrCode::Success; }
};

class NoEnoughCharsError : public BaseError {
 public:
  NoEnoughCharsError(std::size_t n_chars_given) : n_chars_given_(n_chars_given) {}
  ErrCode type() override { return ErrCode::NoEnoughChars; }

 private:
  const std::size_t n_chars_given_;
};

class InvalidCharError : public BaseError {
 public:
  InvalidCharError(char char_given): char_given_(char_given) {}

  ErrCode type() override { return ErrCode::InvalidChar; }

 private:
  const char char_given_;
};

}

#endif  // BASE64_ERRORS_H
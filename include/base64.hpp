#ifndef BASE64_H
#define BASE64_H

#include <cstdint>
#include <vector>
#include <string>
#include <memory>

#include "errors.hpp"

namespace base64 {

void encode(const std::vector<uint8_t> &bytes, std::string &ans);
std::unique_ptr<base64::BaseError> decode(const std::string &s, std::vector<uint8_t> &bytes);

} // base64

#endif  // BASE64_H
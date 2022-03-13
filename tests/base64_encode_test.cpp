#include <cstdint>
#include <string>
#include <vector>

#include <gtest/gtest.h>

#include "base64.hpp"

TEST(Base64EncodeTest, 1Byte) {
  const std::string expect = "WA==";
  const std::vector<uint8_t> bytes { static_cast<uint8_t>('X') };
  std::string actual;
  base64::encode(bytes, actual);
  ASSERT_EQ(expect, actual);
}

TEST(Base64EncodeTest, 2Bytes) {
  const std::string expect = "T0o=";
  const std::vector<uint8_t> bytes { 
    static_cast<uint8_t>('O'), static_cast<uint8_t>('J'),
  };
  std::string actual;
  base64::encode(bytes, actual);
  ASSERT_EQ(expect, actual);
}

TEST(Base64EncodeTest, 3Bytes) {
  const std::string expect = "Q1hY";
  const std::vector<uint8_t> bytes { 
    static_cast<uint8_t>('C'), static_cast<uint8_t>('X'), 
    static_cast<uint8_t>('X'),
  };
  std::string actual;
  base64::encode(bytes, actual);
  ASSERT_EQ(expect, actual);
}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
#include <string>
#include <cassert>
#include <functional>

#include "base64.hpp"

static void encode_1byte(uint32_t cs, std::string &ans);
static void encode_2bytes(uint32_t cs, std::string &ans);
static void encode_3bytes(uint32_t cs, std::string &ans);

static char index_to_char(int i);

static const int MASK = 0x0000003f;

void base64::encode(const std::vector<uint8_t> &bytes, std::string &ans) {
    ans.clear();

    const size_t n_bytes = bytes.size();
    const size_t end = n_bytes / 3 * 3;
    for (size_t i = 0; i < end; i += 3) {
        encode_3bytes((bytes[i] << 16) | (bytes[i + 1] << 8) | bytes[i + 2], ans);
    }

    if (n_bytes % 3 == 1) {
        encode_1byte(bytes[n_bytes - 1], ans);
    } else if (n_bytes % 3 == 2) {
        encode_2bytes((bytes[n_bytes - 2] << 8) | bytes[n_bytes - 1], ans);
    }
}

static void encode_1byte(uint32_t cs, std::string &ans) {
    ans.push_back(index_to_char((cs >> 2) & MASK));
    ans.push_back(index_to_char((cs << 4) & MASK));
    ans.push_back('=');
    ans.push_back('=');
}

static void encode_2bytes(uint32_t cs, std::string &ans) {
    ans.push_back(index_to_char((cs >> 10) & MASK));
    ans.push_back(index_to_char((cs >> 4) & MASK));
    ans.push_back(index_to_char((cs << 2) & MASK));
    ans.push_back('=');
}

static void encode_3bytes(uint32_t cs, std::string &ans) {
    ans.push_back(index_to_char((cs >> 18) & MASK));
    ans.push_back(index_to_char((cs >> 12) & MASK));
    ans.push_back(index_to_char((cs >> 6) & MASK));
    ans.push_back(index_to_char(cs & MASK));
}

static char index_to_char(int i) {
    if (0 <= i && i < 26) {
        return 'A' + i;
    } else if (26 <= i && i < 52) {
        return 'a' + (i - 26);
    } else if (52 <= i && i < 62) {
        return '0' + (i - 52);
    } else if (i == 62) {
        return '+';
    } else if (i == 63) {
        return '/';
    }
    assert(0);
}
#include <iostream>
#include <iomanip>
#include <string>
#include <cassert>
#include <functional>
#include <cstdint>

using namespace std;

int read_input(uint32_t &ans);

string encode_1byte(int cs);
string encode_2bytes(int cs);
string encode_3bytes(int cs);

function<string(int)> jump_table[] = {
    nullptr,
    encode_1byte,
    encode_2bytes,
    encode_3bytes,
};

char index_to_char(int i);

int main() {
    string ans;
    int cs = 0;
    int n_bytes;
    while ((n_bytes = read_input(cs)) > 0) {
        ans += jump_table[n_bytes](cs);
    }
    cout << ans << endl;
}

const int MASK = 0x0000003f;

string encode_1byte(int cs) {
    string ans;
    ans.push_back(index_to_char((cs >> 2) & MASK));
    ans.push_back(index_to_char((cs << 4) & MASK));
    ans.push_back('=');
    ans.push_back('=');
    return ans;
}

string encode_2bytes(int cs) {
    string ans;
    ans.push_back(index_to_char((cs >> 10) & MASK));
    ans.push_back(index_to_char((cs >> 4) & MASK));
    ans.push_back(index_to_char((cs << 2) & MASK));
    ans.push_back('=');
    return ans;
}

string encode_3bytes(int cs) {
    string ans;
    ans.push_back(index_to_char((cs >> 18) & MASK));
    ans.push_back(index_to_char((cs >> 12) & MASK));
    ans.push_back(index_to_char((cs >> 6) & MASK));
    ans.push_back(index_to_char(cs & MASK));
    return ans;
}

int read_input(uint32_t &ans) {
    ans = 0;
    char c;
    for (int i = 0; i < 3; i++) {
        if (!cin.get(c)) {
            return i;
        }
        ans = (ans << 8) | static_cast<uint32_t>(c);
    }
    return 3;
}

char index_to_char(int i) {
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
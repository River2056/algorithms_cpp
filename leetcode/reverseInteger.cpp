#include <iostream>
#include <stdint.h>

class Solution {
public:
    int reverse(int x) {
        int res = 0;
        while (x != 0) {
            int remainder = x % 10;
            x /= 10;
            if (res > INT32_MAX / 10 || (res == INT32_MAX / 10 && remainder > 7)) return 0;
            if (res < INT32_MIN / 10 || (res == INT32_MIN / 10 && remainder < -8)) return 0;
            res *= 10;
            res += remainder;
        }

        return res;
    }
};

int main() {
    Solution s;
    std::cout << "1. " << s.reverse(123) << std::endl;
    std::cout << "2. " << s.reverse(-123) << std::endl;
    std::cout << "3. " << s.reverse(120) << std::endl;
    return 0;
}

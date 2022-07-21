#include <iostream>
#include <sstream>
#include <vector>
#include <map>

class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        std::vector<int> res;
        std::map<int, int> map;
        // std::vector<int>::iterator
        for (int i = 0; i < nums.size(); i++) {
            if (map.count(nums[i])) {
                res.push_back(map[nums[i]]);
                res.push_back(i);
                return res;
            }
            int diff = target - nums[i];
            map[diff] = i;
        }

        return {-1, -1};
    }

    void printResult(std::vector<int> res) {
        std::ostringstream oss;
        for (int n: res)
            oss << n << "\t";
        std::cout << oss.str();
        std::cout << "\n";
    }
};

void test() {
    Solution s;
    std::vector<int> nums({2, 7, 11, 15});
    s.printResult(s.twoSum(nums, 9));
}

void test2() {
    Solution s;
    std::vector<int> nums({3, 2, 4});
    s.printResult(s.twoSum(nums, 6));
}

void test3() {
    Solution s;
    std::vector<int> nums({3, 3});
    s.printResult(s.twoSum(nums, 6));
}

int main() {
    test();
    test2();
    test3();
    return 0;
}

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        return binarySearch(nums, target, 0, nums.size() - 1);
    }

private:
    int binarySearch(vector<int>& nums, int target, int left, int right) {
        if (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) return mid;

            if (target > nums[mid])
                return binarySearch(nums, target, mid + 1, right);

            else if (target < nums[mid])
                return binarySearch(nums, target, left, mid - 1);
        }

        return left;
    }
};

int main() {
    Solution s;
    vector<int> nums({1, 3, 5, 6});
    cout << "1. " << s.searchInsert(nums, 5) << endl; // 2
    cout << "2. " << s.searchInsert(nums, 2) << endl; // 1
    cout << "3. " << s.searchInsert(nums, 7) << endl; // 4
    cout << "4. " << s.searchInsert(nums, 0) << endl; // 0

    nums = {1};
    cout << "5. " << s.searchInsert(nums, 1) << endl; // 0
}

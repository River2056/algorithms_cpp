#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool canAttendMeetings(vector<vector<int>>& intervals) {
        if (intervals.empty())
            return true;

        sort(
            intervals.begin(), 
            intervals.begin() + intervals.size(), 
            [](const vector<int>& a, const vector<int>& b) { return a[0] < b[0]; }
        );

        for (int i = 0; i < intervals.size() - 1; i++) {
            if (intervals[i][1] > intervals[i + 1][0]) {
                return false;
            }
        }

        return true;
    }

    void test() {
        vector<vector<int>> intervals = {
            {0, 30}, {5, 10}, {15, 20}
        };

        bool canAttend = canAttendMeetings(intervals);
        cout << "1. " << canAttend << endl;
    }

    void test2() {
        vector<vector<int>> intervals = {
            {7, 10}, {2, 4}
        };

        bool canAttend = canAttendMeetings(intervals);
        cout << "2. " << canAttend << endl;
    }

    void test3() {
        vector<vector<int>> intervals = {};

        bool canAttend = canAttendMeetings(intervals);
        cout << "3. " << canAttend << endl;
    }
};

int main() {
    Solution s;
    s.test();
    s.test2();
    s.test3();
}

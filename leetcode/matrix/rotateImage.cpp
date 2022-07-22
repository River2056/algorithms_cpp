#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int size = matrix.size() / 2;

        for (int i = 0; i < size; i++) {
            for (int j = i; j < matrix[i].size() - 1 - i; j++) {
                // A, B, C, D positions
                /* cout << "A => " << "i: " << i << ", j: " << j << endl; */
                /* cout << "B => " << "i: " << j << ", j: " << matrix[i].size() - 1 - i << endl; */
                /* cout << "C => " << "i: " << matrix[i].size() - 1 - i << ", j: " << matrix[i].size() - 1 - j << endl; */
                /* cout << "D => " << "i: " << matrix[i].size() - 1 - j << ", j: " << i << endl; */
                
                int tmp = matrix[i][j];
                matrix[i][j] = matrix[j][matrix[i].size() - 1 - i];
                matrix[j][matrix[i].size() - 1 - i] = tmp;

                tmp = matrix[i][j];
                matrix[i][j] = matrix[matrix[i].size() - 1 - i][matrix[i].size() - 1 - j];
                matrix[matrix[i].size() - 1 - i][matrix[i].size() - 1 - j] = tmp;

                tmp = matrix[i][j];
                matrix[i][j] = matrix[matrix[i].size() - 1 - j][i];
                matrix[matrix[i].size() - 1 - j][i] = tmp;
            }
        }
    }

    void test() {
        vector<vector<int>> matrix = {
            {1,  2,  3,  4},
            {5,  6,  7,  8},
            {9,  10, 11, 12},
            {13, 14, 15, 16}
        };

        cout << "before: " << endl;
        printMatrix(matrix);

        rotate(matrix);
        
        cout << endl;
        cout << "after: " << endl;
        printMatrix(matrix);
    }

private:
    void printMatrix(vector<vector<int>>& matrix) {
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[i].size(); j++) {
                cout << matrix[i][j] << "\t";
            }
            cout << endl;
        }
    }
};

int main() {
    Solution s;
    s.test();
    return 0;
}

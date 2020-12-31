#include <bits/stdc++.h>
using namespace std;

// TLE: 126/128 passed
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        return helper(matrix, 0, m - 1, 0, n - 1, target);
    }
private: 
    bool helper(vector<vector<int>> &matrix, int m1, int m2, int n1, int n2, int target) {
        if (m1 > m2 || n1 > n2) return false;
        if (m1 == m2 && n1 == n2 && matrix[m1][n1] != target) return false;
        int mPivot = (m1 + m2) / 2, nPivot = (n1 + n2) / 2;
        if (matrix[mPivot][nPivot] == target) return true;
        return helper(matrix, m1, mPivot, n1, nPivot, target) ||
               helper(matrix, mPivot + 1, m2, n1, nPivot, target) ||
               helper(matrix, m1, mPivot, nPivot + 1, n2, target) ||
               helper(matrix, mPivot + 1, m2, nPivot + 1, n2, target);
    }
};

int main() {
    vector<vector<int>> matrix = {{1,4,7,11,15},
                                  {2,5,8,12,19},
                                  {3,6,9,16,22},
                                  {10,13,14,17,24},
                                  {18,21,23,26,30}};
    // int target = 5;
    int target = 20;
    Solution sol;
    cout << sol.searchMatrix(matrix, target) << endl;

    return 0;
}
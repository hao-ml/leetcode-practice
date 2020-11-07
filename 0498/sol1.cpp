#include <bits/stdc++.h>
using namespace std;

void printVector(vector<int> &nums) {
    for (int num : nums) {
        cout << num << ' ';
    }
    cout << endl;
}

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        if (matrix.empty() || matrix.at(0).empty()) return ans;
        int m = matrix.size(), n = matrix.at(0).size();
        int i = 0, j = 0, count = 0;
        bool isUp = true;

        while (count < m * n) {
            ans.push_back(matrix.at(i).at(j));
            if (isUp) {
                if (j == n - 1) {
                    i++;
                    isUp = false;
                }
                else if (i == 0) {
                    j++;
                    isUp = false;
                }
                else {
                    i--;
                    j++;
                }
            }
            else {
                if (i == m - 1) {
                    j++;
                    isUp = true;
                }
                else if (j == 0) {
                    i++;
                    isUp = true;
                }
                else {
                    i++;
                    j--;
                }
            }
            count++;
        }

        return ans;
    }
};

int main() {
    vector<vector<int>> matrix = {{1,2,3}, {4,5,6}, {7,8,9}};
    Solution sol;
    auto ans = sol.findDiagonalOrder(matrix);
    printVector(ans);

    return 0;
}
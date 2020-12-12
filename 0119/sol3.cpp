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
    vector<int> getRow(int rowIndex) {
        vector<int> ans(rowIndex + 1);
        unordered_map<int, unordered_map<int, int>> calculated;
        for (int i = 0; i < ans.size(); i++) {
            ans[i] = helper(rowIndex, i, calculated);
        }
        
        return ans;
    }
private:
    int helper(int row, int col, unordered_map<int, unordered_map<int, int>> &calculated) {
        if (calculated.count(row) && calculated[row].count(col)) {
            return calculated[row][col];
        }
        int ans;
        if (col == 0 || col == row) ans = 1;
        else ans = helper(row - 1, col - 1, calculated) + helper(row - 1, col, calculated);
        calculated[row][col] = ans; 
        return ans;
    }
};

int main() {
    int rowIndex = 29;
    Solution sol;
    auto ans = sol.getRow(rowIndex);
    printVector(ans);

    return 0;
}
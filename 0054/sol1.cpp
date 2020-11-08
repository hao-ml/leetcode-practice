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
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix.at(0).empty()) return {};
        
        int m = matrix.size(), n = matrix.at(0).size();
        int up = 0, down = m - 1, left = 0, right = n - 1;
        int i = 0, j = 0;
        string direction = "right";
        vector<int> ans(m * n);
        
        for (int k = 0; k < m * n; k++) {
            ans.at(k) = matrix.at(i).at(j);
            if (direction == "right") {
                if (j == right) {i++; direction = "down"; up++;}
                else j++;
            }
            else if (direction == "down") {
                if (i == down) {j--; direction = "left"; right--;}
                else i++;
            }
            else if (direction == "left") {
                if (j == left) {i--; direction = "up"; down--;}
                else j--;
            }
            else if (direction == "up") {
                if (i == up) {j++; direction = "right"; left++;}
                else i--;
            }
        } 

        return ans;
    }
};

int main() {
    vector<vector<int>> matrix = {{1,2,3}, {4,5,6}, {7,8,9}};
    Solution sol;
    auto ans = sol.spiralOrder(matrix);
    printVector(ans);

    return 0;
}
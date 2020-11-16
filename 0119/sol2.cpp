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
        ans.at(0) = 1;
        
        for (int i = 1; i <= rowIndex; i++)
            for (int j = i; j >= 1; j--) 
                ans.at(j) += ans.at(j - 1);
        
        return ans;
    }
};

int main() {
    int rowIndex = 11;
    Solution sol;
    auto ans = sol.getRow(rowIndex);
    printVector(ans);

    return 0;
}
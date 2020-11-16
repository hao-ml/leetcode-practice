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
        
        for (int i = 1; i <= rowIndex / 2; i++) {
            auto factor =  1.0 * (rowIndex + 1 - i) / i;
            ans.at(i) = round(ans.at(i-1) * factor);
        }
        for (int i = rowIndex; i > rowIndex / 2; i--) 
            ans.at(i) = ans.at(rowIndex - i);
        
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
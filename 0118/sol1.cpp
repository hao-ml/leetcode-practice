#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        if (!numRows) return {};

        vector<vector<int>> ans;

        for (int i = 0; i < numRows; i++) {
            vector<int> vec;
            for (int j = 0; j <= i; j++) {
                if (j == 0 || j == i) vec.push_back(1);
                else vec.push_back(ans.at(i-1).at(j-1)+ans.at(i-1).at(j));
            }
            ans.push_back(vec);
        }

        return ans;
    }
};

int main() {
    int numRows = 5;
    Solution sol;
    auto ans = sol.generate(numRows);

    return 0;
}
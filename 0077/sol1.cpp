#include <bits/stdc++.h>
using namespace std;

void printMatrix(vector<vector<int>> &mat) {
    if (mat.size() == 0) cout << "NULL" << endl;
    else {
        for (auto arr : mat) {
            if (arr.size() == 0) cout << "NULL";
            else for (auto a : arr) cout << a << ' ';
            cout << endl;
        }
    }
}

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> cmb;
        helper(n, k, 1, ans, cmb);
        return ans;
    }
private:
    void helper(int n, int k, int level, vector<vector<int>> &ans, vector<int> &cmb) {
        if (cmb.size() == k) {ans.push_back(cmb); return;}
        for (int i = level; i <= n; i++) {
            cmb.push_back(i);
            helper(n, k, i + 1, ans, cmb);
            cmb.pop_back();
        }
    }
};

int main() {
    int n = 4, k = 2;
    Solution sol;
    auto ans = sol.combine(n, k);
    printMatrix(ans);    

    return 0;
}
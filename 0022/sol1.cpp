#include <bits/stdc++.h>
using namespace std;

void printArray(vector<string> &arr) {
    if (arr.size() == 0) cout << "NULL";
    else {
        for (auto a : arr) cout << a << ' ';
    }
    cout << endl;
}

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        backtrack(ans, "", 0, 0, n);
        return ans;
    }
private:
    void backtrack(vector<string> &ans, string str, int nl, int nr, int n) {
        if (str.length() == n * 2) {ans.push_back(str); return;}
        if (nl < n) {
            str.push_back('(');
            backtrack(ans, str, nl + 1, nr, n);
            str.pop_back();
        }
        if (nr < nl) {
            str.push_back(')');
            backtrack(ans, str, nl, nr + 1, n);
            str.pop_back();
        }
    }
};

int main() {
    int n = 3;
    Solution sol;
    auto ans = sol.generateParenthesis(n);
    printArray(ans);

    return 0;
}
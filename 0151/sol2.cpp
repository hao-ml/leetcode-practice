
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        istringstream is(s);
        string sub;
        is >> s;
        while (is >> sub) s = sub + " " + s;
        if (!s.empty() && s[0] == ' ') s = "";
        return s;
    }
};

int main() {
    string s = "  the sky     is blue  ";
    Solution sol;
    auto ans = sol.reverseWords(s);
    cout << ans << endl;
    return 0;
}
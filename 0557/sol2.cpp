
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        if (s.empty()) return "";
        string ans = "", word = "";
        istringstream is(s);

        while (is >> word) {
            reverse(word.begin(), word.end());
            ans += word + " ";
        }
        ans.pop_back();

        return ans;
    }
};

int main() {
    string s = "the sky is blue";
    Solution sol;
    auto ans = sol.reverseWords(s);
    cout << ans << endl;
    return 0;
}
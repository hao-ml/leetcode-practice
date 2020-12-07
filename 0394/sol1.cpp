#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string decodeString(string s) {
        int n = s.length();
        string ans;
        stack<char> stk;

        for (int i = 0; i < n; i++) {
            if (isalpha(s[i]) && stk.empty()) {
                ans.push_back(s[i]);
                continue;
            }
            if (s[i] != ']') {
                stk.push(s[i]);
                continue;
            }
            string repeat;
            char c = stk.top(); stk.pop();
            while (c != '[') {
                repeat.push_back(c);
                c = stk.top(); stk.pop();
            }
            reverse(repeat.begin(), repeat.end());
            string strK;
            while(!stk.empty() && isdigit(stk.top())) {
                strK = stk.top() + strK;
                stk.pop();
            }
            int k = stoi(strK);
            string encoded;
            for(; k > 0; k--) encoded += repeat;
            if (stk.empty()) ans += encoded;
            else for (auto ch : encoded) stk.push(ch);
        }

        return ans;
    }
};

int main() {
    // string s = "3[a]2[bc]";
    // string s = "3[a2[c]]";
    // string s = "2[abc]3[cd]ef";
    string s = "abc3[cd]xyz";
    Solution sol;

    cout << sol.decodeString(s) << endl;

    return 0;
} 
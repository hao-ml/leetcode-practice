
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        if (s.empty()) return false;

        int n = s.length();
        stack<char> stk;

        stk.push(s.at(0));
        for (int i = 1; i < n; i++) {
            if (stk.empty()) {stk.push(s.at(i)); continue;}
            char c = stk.top();
            if (c == '(') {
                if (s.at(i) == ')') stk.pop();
                else stk.push(s.at(i));
            }
            else if (c == '[') {
                if (s.at(i) == ']') stk.pop();
                else stk.push(s.at(i));
            }
            else if (c == '{') {
                if (s.at(i) == '}') stk.pop();
                else stk.push(s.at(i));
            }
            else return false;
        }

        return stk.empty();
    }
};

int main() {
    string s = "()[]{}";
    Solution sol;

    cout << sol.isValid(s) << endl;

    return 0;
}
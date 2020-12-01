
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        if (tokens.empty()) return 0;
        stack<int> stk;
        for (int i = 0; i < tokens.size(); i++) {
            string token = tokens.at(i);
            if (token == "+" || token == "-" || token == "*" || token == "/") {
                int b = stk.top(); stk.pop();
                int a = stk.top(); stk.pop();
                int ans;
                if (token == "+") ans = a + b;
                else if (token == "-") ans = a - b;
                else if (token == "*") ans = a * b;
                else if (token == "/") ans = a / b;
                stk.push(ans);
            }
            else stk.push(stoi(token));
        }
        return stk.top();
    }
};

int main() {
    vector<string> tokens = {"4", "13", "5", "/", "+"};
    Solution sol;

    cout << sol.evalRPN(tokens) << endl;

    return 0;
}
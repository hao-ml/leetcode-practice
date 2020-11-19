
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        if (s.empty()) return "";
        int n = s.size();
        int i = 0, j = 0;

        while (i < n && j < n) {
            if (s.at(j) != ' ') j++;
            else {
                reverse(s.begin()+i, s.begin()+j);
                j++; i = j;
            }
        }
        reverse(s.begin()+i, s.end());

        return s;
    }
};

int main() {
    string s = "the sky is blue";
    Solution sol;
    auto ans = sol.reverseWords(s);
    cout << ans << endl;
    return 0;
}
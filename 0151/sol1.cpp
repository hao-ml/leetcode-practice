
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        if (s.empty()) return "";
        reverse(s.begin(), s.end());
        while (!s.empty() && s.at(0) == ' ') s.erase(0, 1);
        while (!s.empty() && s.at(s.length() - 1) == ' ') s.erase(s.length() - 1, 1);
        int i = 0, n = s.length();
        while (i + 1 < n) {
            if (s.at(i) == ' ' && s.at(i + 1) == ' ') {
                s.erase(i + 1, 1);
                n--;
            }
            else i++;
        }
        n = s.length();
        int first = 0, last = 0;
        while (first < n && last < n) {
            if (s.at(last) != ' ') last++;
            else {
                if (first != last) reverse(s.begin() + first, s.begin() + last);
                last++;
                first = last;
            }
        }
        if (first != last) reverse(s.begin() + first, s.end());

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
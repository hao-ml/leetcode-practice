
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        int i = 0, n = s.size();
        reverse(s.begin(), s.end());
        for (int j = 0; j < n; j++) {
            if (s.at(j) != ' '){
                if (i != 0) s.at(i++) = ' ';
                int k = j;
                while (k < n && s.at(k) != ' ') s.at(i++) = s.at(k++);
                reverse(s.begin() + i - (k - j), s.begin() + i);
                j = k;
            }
        }
        s.resize(i);
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
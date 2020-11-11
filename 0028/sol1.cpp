#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.empty()) return 0;
        int m = haystack.length(), n = needle.length();

        for (int j = 0; j < m - n + 1; j++) {
            int k = j; cout << k << endl;
            for (int i = 0; i < n; i++) {
                if (needle.at(i) != haystack.at(k)) break;
                k++;
            }
            if (k - j == n) return j;
        }

        return -1;
    }
};

int main() {
    string haystack = "abb", needle = "abaaa";
    Solution sol;
    cout << sol.strStr(haystack, needle) << endl;

    return 0;
}
#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    string addBinary(string a, string b) {
        int ia = a.size() - 1, ib = b.size() - 1;
        int carry = 0;
        string ans = "";

        while (ia >= 0 && ib >= 0) {
            int sum = (a.at(ia) - '0') + (b.at(ib) - '0') + carry;
            insertBinaryDigit(sum, carry, ans);
            ia--; ib--;
        }

        if (ia < 0) {
            while (ib >= 0) {
                int sum = (b.at(ib) - '0') + carry;
                insertBinaryDigit(sum, carry, ans);
                ib--;
            }
        }
        else if (ib < 0) {
            while (ia >= 0) {
                int sum = (a.at(ia) - '0') + carry;
                insertBinaryDigit(sum, carry, ans);
                ia--;
            }
        }

        if (carry) ans = "1" + ans;

        return ans;
    }

private: 
    void insertBinaryDigit(int &sum, int &carry, string &ans) {
        if (sum > 1) {sum -= 2; carry = 1;}
        else carry = 0;
        ans = to_string(sum) + ans;
    }
};

int main() {
    string a = "1010", b = "1011";
    Solution sol;
    cout << sol.addBinary(a, b) << endl;

    return 0;
}
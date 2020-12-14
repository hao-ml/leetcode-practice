#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double myPow(double x, long n) {
        if (n == 0) return 1.0;
        auto nPos = (n > 0) ? n : -n;
        auto ans = helper(x, nPos);
        if (n < 0) ans = 1 / ans;
        return ans;
    }
private:
    double helper(double x, long n) {
        if (n == 1) return x;
        auto ans = helper(x, n / 2);
        ans *= ans;
        if (n % 2 == 1) ans *= x;
        return ans;
    }
};

int main() {

    // double x = 2.0;
    // int n = -2;    
    double x = 0.00001;
    long n = 2147483648;

    Solution s;
    cout << s.myPow(x, n) << endl;

    return 0;
  
}
#include <bits/stdc++.h>
using namespace std;

// Time Limit Exceeded
// 31 / 45 test cases passed.
class Solution {
public:
    int climbStairs(int n) {
        
        if (n == 1) {
            return 1;
        }
        else if (n == 2) {
            return 2;
        }

        return climbStairs(n - 1) + climbStairs(n - 2);
    }
};

int main() {
    int n;
    cin >> n;

    Solution sol;
    cout << sol.climbStairs(n) << endl;

    return 0;
  
}

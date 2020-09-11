#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int climbStairs(int n) {
        
        if (n == 1) return 1;

        vector<int> dp(n+1);
        
        dp.at(1) = 1;
        dp.at(2) = 2;

        for (int i = 3; i < n + 1; i++) {
            dp.at(i) = dp.at(i-1) + dp.at(i-2);
        }

        return dp.at(n);
        
    }
};

int main() {
    int n;
    cin >> n;

    Solution sol;
    cout << sol.climbStairs(n) << endl;

    return 0;
  
}

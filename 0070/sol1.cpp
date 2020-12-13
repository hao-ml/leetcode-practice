#include <bits/stdc++.h>
using namespace std;

// Time Limit Exceeded
// 31 / 45 test cases passed.
// --> memorization --> AC
class Solution {
public:
    int climbStairs(int n) {
        unordered_map<int, int> cache;
        return helper(n, cache);
    }
private:
    int helper(int n, unordered_map<int, int> &cache) {
        if (n < 3) return n;
        int ans;
        if (cache.count(n)) ans = cache[n];
        else {
            ans = helper(n - 1, cache) + helper(n - 2, cache);
            cache[n] = ans;
        }
        return ans;
    }
};

int main() {
    int n;
    cin >> n;

    Solution sol;
    cout << sol.climbStairs(n) << endl;

    return 0;
  
}

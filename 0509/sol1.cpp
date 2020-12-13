#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int fib(int N) {
        unordered_map<int, int> cache;
        return helper(N, cache);
    }
private:
    int helper(int N, unordered_map<int, int> &cache) {
        if (N == 0 || N == 1) return N;
        int ans;
        if (cache.count(N)) return ans = cache[N];
        else {
            ans = helper(N - 1, cache) + helper(N - 2, cache);
            cache[N] = ans;
        }
        
        return ans;
    }
};

int main() {
    int N = 4;
    Solution sol;
    cout << sol.fib(N) << endl;

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        int n = nums.size();
        vector<unordered_map<int, int>> dp(n + 1);
        dp.at(0)[0] = 1;

        for (int i = 0; i < n; i++) {
            for (auto &p : dp.at(i)) {
                auto sum = p.first, cnt = p.second;
                dp.at(i + 1)[sum + nums.at(i)] += cnt;
                dp.at(i + 1)[sum - nums.at(i)] += cnt;
            }
        }

        return dp.at(n)[S];
    }
};

int main() {
    vector<int> nums = {1, 1, 1, 1, 1};
    int S = 3;
    Solution sol;

    cout << sol.findTargetSumWays(nums, S) << endl;

    return 0;
} 
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (S > sum || (S + sum) % 2 != 0) return 0;

        int target = (S + sum) / 2;
        vector<int> dp(target+1);
        dp.at(0) = 1;

        for (auto num : nums) {
            for (int i = target; i >= num; i--) 
                dp.at(i) += dp.at(i - num);
        }

        return dp.at(target);
    }
};

int main() {
    vector<int> nums = {1, 1, 1, 1, 1};
    int S = 3;
    Solution sol;

    cout << sol.findTargetSumWays(nums, S) << endl;

    return 0;
} 
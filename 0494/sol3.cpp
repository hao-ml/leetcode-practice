#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        int ans = 0, n = nums.size();
        vector<int> sums(n);
        sums.at(n - 1) = nums.at(n - 1);
        for (int i = n - 2; i >= 0; i--) 
            sums.at(i) = sums.at(i + 1) + nums.at(i);
        findTargetSumWaysFunc(nums, 0, S, ans, sums);
        return ans;
    }
private:
    void findTargetSumWaysFunc(vector<int>& nums, int i, long S, int &ans, vector<int>& sums) {
        int n = nums.size();
        if (i == n) {
            if (S == 0) ans++;
            return;
        }
        if (S > sums.at(i)) return;

        findTargetSumWaysFunc(nums, i+1, S+nums.at(i), ans, sums);
        findTargetSumWaysFunc(nums, i+1, S-nums.at(i), ans, sums);
    }
};

int main() {
    vector<int> nums = {1, 1, 1, 1, 1};
    int S = 3;
    Solution sol;

    cout << sol.findTargetSumWays(nums, S) << endl;

    return 0;
} 
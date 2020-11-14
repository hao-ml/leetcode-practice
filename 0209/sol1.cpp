#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int n = nums.size();
        int fast = 0, slow = 0;
        bool isFast = true;
        int sum = 0;
        int ans = n + 1;
        while (fast < n && slow < n) {
            if (isFast) sum += nums.at(fast);
            if (sum < s) {fast++; isFast = true;}
            else {
                if (fast - slow + 1 < ans) ans = fast - slow + 1;
                sum -= nums.at(slow++); isFast = false;
            }
        }
        return (ans == n + 1) ? 0 : ans;
    }
};

int main() {
    vector<int> nums = {2,3,1,2,4,3};
    int s = 7;
    Solution sol;
    auto ans = sol.minSubArrayLen(s, nums);
    cout << ans << endl;

    return 0;
}
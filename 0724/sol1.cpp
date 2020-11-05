#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sum = 0;
        for (int num : nums) sum += num;

        int currSum = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (currSum == (sum-nums.at(i)-currSum)) return i;
            currSum += nums.at(i);
        }
        return -1;
    }
};

int main() {
    vector<int> nums = {1,7,3,6,5,6};
    Solution sol;
    cout << sol.pivotIndex(nums) << endl;
    return 0;
}
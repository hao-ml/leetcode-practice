#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int first = -1, second = -2;
        int iFirst = -1, iSecond = -1;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            if (nums.at(i) > first) {
                second = first;
                first = nums.at(i);
                iFirst = i;
            }
            else if (nums.at(i) > second) second = nums.at(i);
        }
        
        if (first >= 2 * second) return iFirst;
        else return -1;
    }
};

int main() {
    vector<int> nums = {0, 0, 0, 1};
    Solution sol;
    cout << sol.dominantIndex(nums) << endl;
    return 0;
}
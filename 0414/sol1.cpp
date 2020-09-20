#include <bits/stdc++.h>
using namespace std;

void printVector(vector<int> &nums) {
    for (int num : nums) {
        cout << num << ' ';
    }
    cout << endl;
}

class Solution {
public:
    int thirdMax(vector<int>& nums) {
        int len = nums.size();
        sort(nums.begin(), nums.end());

        int ranking = 1;
        int curIdx = len - 1;
        int ans = nums.at(curIdx);
        
        while (ranking < 3 && curIdx >= 0) {
            if (nums.at(curIdx) < ans) {
                ans = nums.at(curIdx);
                ranking++;
            }
            curIdx--;
        }

        if (ranking < 3) ans = nums.at(len - 1);

        return ans;
    }
};

int main() {

    int n;
    cin >> n;
    
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums.at(i);
    }

    Solution sol;
    auto ans = sol.thirdMax(nums);

    cout << ans << endl;

    return 0;
  
}
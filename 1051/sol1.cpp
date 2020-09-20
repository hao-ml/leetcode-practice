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
    int heightChecker(vector<int>& heights) {
        vector<int> heights_old(heights);
        sort(heights.begin(), heights.end());
        int ans = 0;
        for (int i = 0; i < heights.size(); i++) {
            if (heights_old.at(i) != heights.at(i)) ans++;
        }

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
    auto ans = sol.heightChecker(nums);

    cout << ans << endl;

    return 0;
  
}
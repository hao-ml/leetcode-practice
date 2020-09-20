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
        long int max1 = INT64_MIN;
        long int max2 = INT64_MIN;
        long int max3 = INT64_MIN;

        for (auto num : nums) {
            if (num > max1) {
                max3 = max2;
                max2 = max1;
                max1 = num;
            }
            else if (num > max2 && num < max1) {
                max3 = max2;
                max2 = num;
            }
            else if (num > max3 && num < max2) {
                max3 = num;
            }
        }

        if (max3 == INT64_MIN) max3 = max1;

        return max3;
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
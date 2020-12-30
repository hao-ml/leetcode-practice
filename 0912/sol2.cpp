#include <bits/stdc++.h>
using namespace std;

void printVector(vector<int> &nums) {
    for (int num : nums) {
        cout << num << ' ';
    }
    cout << endl;
}

// TODO: Merge sort, bottom-up
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        return nums;
    }
};

int main() {
    vector<int> nums = {5,1,1,2,0,0};
    printVector(nums);
    Solution sol;
    auto ans = sol.sortArray(nums);
    printVector(ans);

    return 0;
}
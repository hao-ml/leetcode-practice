#include <bits/stdc++.h>
using namespace std;

void printVector(vector<int> &nums) {
    for (int num : nums) {
        cout << num << ' ';
    }
    cout << endl;
}

// Merge sort, top-down
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) return nums;
        int pivot = n / 2;
        vector<int> l(nums.begin(), nums.begin() + pivot);
        vector<int> r(nums.begin() + pivot, nums.end());
        auto nums1 = sortArray(l);
        auto nums2 = sortArray(r);
        
        return helper(nums1, nums2);
    }
private:
    vector<int> helper(vector<int> &nums1, vector<int> &nums2) {
        int n1 = nums1.size(), n2 = nums2.size();
        vector<int> ans(n1 + n2);
        int i1 = 0, i2 = 0, i = 0;
        
        while(i1 < n1 && i2 < n2) {
            if (nums1[i1] < nums2[i2]) ans[i++] = nums1[i1++];
            else ans[i++] = nums2[i2++];
        }
        while(i1 < n1) ans[i++] = nums1[i1++];
        while(i2 < n2) ans[i++] = nums2[i2++];
        
        return ans;
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
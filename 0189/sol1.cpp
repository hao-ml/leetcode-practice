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
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k %= n;
        int slow = 0;

        while (k) {
            int fast = slow + n - k;
            while (fast < nums.size()) {
                swap(nums.at(fast), nums.at(slow));
                fast++;
                slow++;
            }
            n -= k;
            k %= n;
        }
    }
};

int main() {
    vector<int> nums = {1,2,3,4,5,6,7};
    int k = 3;
    Solution sol;
    sol.rotate(nums, k);
    printVector(nums);

    return 0;
}
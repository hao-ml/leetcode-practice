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
        if (k % nums.size() == 0) return;
        int n = nums.size();
        k %= n;
        int count = 0, start = 0, cur = 0, val = nums.at(cur);
        while (count < n) {
            cur += k;
            cur %= n;
            swap(val, nums.at(cur));
            if (cur == start) {
                cur = ++start;
                val = nums.at(cur);}
            count++;
        }
    }
};

int main() {
    vector<int> nums = {1,2};
    int k = 2;
    Solution sol;
    sol.rotate(nums, k);
    printVector(nums);

    return 0;
}
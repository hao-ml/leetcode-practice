#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry = 1;
        for (int i = digits.size() - 1; i >= 0; i--) {
            if (carry == 0) return digits;
            int sum = digits.at(i) + carry;
            digits.at(i) = sum % 10;
            carry = sum / 10;
        }
        if (carry == 1) digits.insert(digits.begin(), 1);

        return digits;
    }
};

int main() {
    vector<int> nums = {1,2,3};
    Solution sol;
    sol.plusOne(nums);
    return 0;
}
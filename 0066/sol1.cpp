#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        reverse(digits.begin(), digits.end());
        int up = 0;
        for (int i = 0; i < digits.size(); i++) {
            int sum = 0;
            sum = up + digits.at(i);
            if (i == 0) sum++;
            if (sum > 9) {
                sum = sum - 10;
                up = 1;
            } 
            else up = 0;
            digits.at(i) = sum;
        }
        if (up == 1) digits.push_back(1);
        reverse(digits.begin(), digits.end());
        
        return digits;
    }
};

int main() {
    vector<int> nums = {1,2,3};
    Solution sol;
    sol.plusOne(nums);
    return 0;
}
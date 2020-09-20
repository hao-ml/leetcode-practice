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
    void moveZeroes(vector<int>& nums) {
        int readIdx = 0;
        int writeIdx = 0;
        while (readIdx < nums.size()) {
            if (nums.at(writeIdx) != 0) writeIdx++;
            else {
                if (nums.at(readIdx) != 0) {
                    nums.at(writeIdx) = nums.at(readIdx);
                    nums.at(readIdx) = 0;
                    writeIdx++;
                }
            }
            readIdx++;
        }
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
    sol.moveZeroes(nums);

    printVector(nums);

    return 0;
  
}
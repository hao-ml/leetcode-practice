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
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) return 0;
        
        int i = 0;
        int j = 0;
        while (i < nums.size()) {
            if (nums.at(i) > nums.at(j)) {
                j++;
                nums.at(j) = nums.at(i);
            }
            i++;
        }

        return (j + 1);
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
    cout << sol.removeDuplicates(nums) << endl;

    printVector(nums);

    return 0;
  
}
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
    int removeElement(vector<int>& nums, int val) {
        int i = 0;
        int j = nums.size() - 1;
        int ans = nums.size();

        while (i <= j) {
            if (nums.at(i) == val) {
                if (nums.at(j) == val) {
                    j--;
                    ans--;
                }
                else {
                    nums.at(i) = nums.at(j);
                    i++;
                    j--;
                    ans--;
                }
            }
            else i++;
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

    int val;
    cin >> val;

    Solution sol;
    cout << sol.removeElement(nums, val) << endl;

    printVector(nums);

    return 0;
  
}
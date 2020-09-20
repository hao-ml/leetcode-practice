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
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> ans;

        int len = nums.size();        
        vector<int> counts(len, 0);

        for (auto num : nums) counts.at(num-1)++;
        for (int i = 0; i < len; i++) {
            if (counts.at(i) == 0) ans.push_back(i+1); 
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

    Solution sol;
    auto ans = sol.findDisappearedNumbers(nums);

    printVector(ans);

    return 0;
  
}
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
    vector<int> replaceElements(vector<int>& arr) {
        int len = arr.size();
        int curMax = -1;

        for (int i = len - 1; i >= 0; i--) {
            int thisNum = arr.at(i);
            arr.at(i) = curMax;
            if (thisNum > curMax) curMax = thisNum;
        }

        return arr;
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
    auto ans = sol.replaceElements(nums);

    printVector(ans);

    return 0;
  
}
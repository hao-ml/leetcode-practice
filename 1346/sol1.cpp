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
    bool checkIfExist(vector<int>& arr) {
        set<int> arrSet;
        for (int i = 0; i < arr.size(); i++) {
            int num = arr.at(i);
            if (arrSet.find(num) != arrSet.end()) return true;
            if (num % 2 == 0) arrSet.insert(num / 2);
            arrSet.insert(num * 2);
        }

        return false;
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
    cout << sol.checkIfExist(nums) << endl;

    printVector(nums);

    return 0;
  
}
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
    bool validMountainArray(vector<int>& A) {
        if (A.size() < 3) return false;
        
        int i = 0;
        while (i < A.size() - 1 && A.at(i+1) > A.at(i)) i++;

        int j = A.size() - 1;
        while (j > 0 && A.at(j-1) > A.at(j)) j--;

        return (i == j && i > 0 && j < A.size() - 1);
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
    cout << sol.validMountainArray(nums) << endl;

    printVector(nums);

    return 0;
  
}
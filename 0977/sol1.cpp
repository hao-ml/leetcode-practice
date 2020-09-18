#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        for (int i = 0; i < A.size(); i++) { 
            A.at(i) *= A.at(i);
        }
        sort(A.begin(), A.end());
        
        return A;
    }
};

void printVector(vector<int> &nums) {
    for (int num : nums) {
        cout << num << ' ';
    }
    cout << endl;
}

int main() {

    int N;
    cin >> N;
    vector<int> nums(N);
    for (int i = 0; i < N; i++) {
        cin >> nums.at(i);
    }

    Solution sol;
    vector<int> A = sol.sortedSquares(nums);
    printVector(A);

    return 0;
  
}
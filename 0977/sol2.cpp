#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        int N = A.size();
        vector<int> ans(N);
        int i = 0;
        int j = N - 1;
        int k = N - 1;

        while (i <= j) {
            int ai = A.at(i) * A.at(i);
            int aj = A.at(j) * A.at(j);
            if (ai > aj) {
                ans.at(k) = ai;
                i++;
            }
            else {
                ans.at(k) = aj;
                j--;
            }
            k--;
        }        
        
        return ans;
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
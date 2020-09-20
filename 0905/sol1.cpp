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
    vector<int> sortArrayByParity(vector<int>& A) {
        int len = A.size();
        int i = 0;
        int j = len - 1;

        while (i < j) {
            if (A.at(i) % 2 == 0) i++;
            else {
                if (A.at(j) % 2 != 0) j--;
                else {
                    int temp = A.at(i);
                    A.at(i) = A.at(j);
                    A.at(j) = temp;
                    i++;
                    j--;
                }
            }
        }
        return A;
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
    auto ans = sol.sortArrayByParity(nums);

    printVector(ans);

    return 0;
  
}
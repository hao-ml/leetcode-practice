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
    void duplicateZeros(vector<int>& arr) {
        int len = arr.size();
        for (int i = 0; i < len; i++) {
            if (arr.at(i) == 0 && (i < len - 1)) {
                vector<int> subArr (arr.begin(), arr.begin()+i+1);
                subArr.insert(subArr.end(), arr.begin()+i, arr.end()-1);
                arr.assign(subArr.begin(), subArr.end());
                i++;
            }
        }
    }
};

int main() {

    int N;
    cin >> N;
    vector<int> nums(N);
    for (int i = 0; i < N; i++) {
        cin >> nums.at(i);
    }

    Solution sol;
    sol.duplicateZeros(nums);

    printVector(nums);

    return 0;
  
}
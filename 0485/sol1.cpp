#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int c = 0;
        int maxCount = 0;
        for (int num : nums) {
            if (num == 1) {
                c++;
            }
            else {
                if (maxCount < c) maxCount = c;
                c = 0;
            }
        }
        if (maxCount < c) maxCount = c;

        return maxCount;
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
    cout << sol.findMaxConsecutiveOnes(nums) << endl;

    return 0;
  
}
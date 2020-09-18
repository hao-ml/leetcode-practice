#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int ans = 0;
        for (int num : nums) {
            string str = to_string(num);
            if (str.size() % 2 == 0) ans++;
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
    cout << sol.findNumbers(nums) << endl;

    return 0;
  
}
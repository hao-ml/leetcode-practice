#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        queue<int> q;
        for (int i = 0; i < arr.size(); i++) {
            if (arr.at(i) == 0) {
                q.push(0);
            }
            q.push(arr.at(i));
            arr.at(i) = q.front();
            q.pop();
        }
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
    sol.duplicateZeros(nums);

    printVector(nums);

    return 0;
  
}
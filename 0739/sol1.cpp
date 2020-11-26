
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
    vector<int> dailyTemperatures(vector<int>& T) {
        if (T.empty()) return {};
        
        int n = T.size();
        stack<int> stkIdx;
        vector<int> vec(n);

        int i = 0;
        while (i < n) {
            if (stkIdx.empty() || T.at(i) <= T.at(stkIdx.top())) {
                stkIdx.push(i++);
                continue;
            }
            vec.at(stkIdx.top()) = i - stkIdx.top();
            stkIdx.pop();
        }

        return vec;
    }
};

int main() {
    vector<int> T = {73, 74, 75, 71, 69, 72, 76, 73};
    Solution sol;

    auto ans = sol.dailyTemperatures(T);
    printVector(ans);

    return 0;
}
#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        map<int, int> M;
        int n = numbers.size();
        vector<int> ans(2);
        for (int i = 0; i < n; i++) {
            int a = numbers.at(i);
            int b = target - a;
            if (M.find(b) != M.end()) {
                ans.at(0) = M.at(b) + 1;
                ans.at(1) = i + 1;
                return ans;
            }
            M[a] = i;
        }
        return ans;
    }
};

int main() {
    vector<int> numbers = {2,7,11,15};
    int target = 9;
    Solution sol;
    auto ans = sol.twoSum(numbers, target);
    cout << ans.at(0) << " " << ans.at(1) << endl;

    return 0;
}
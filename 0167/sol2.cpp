#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();
        int i = 0, j = n - 1;
        vector<int> ans(2);
        while(i < j) {
            int sum = numbers.at(i) + numbers.at(j);
            if (sum == target) {
                ans.at(0) = i + 1; 
                ans.at(1) = j + 1;
                break;
            }
            else if (sum > target) j--;
            else i++;
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
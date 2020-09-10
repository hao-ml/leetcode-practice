#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;

        map<int, int> m;
  for (int n : nums1) {
    m[n] += 1;
  }
  for (int n : nums2) {
    if (m[n] > 0) {
      ans.push_back(n);
      m[n] -= 1;
    }
  }
        return ans;
    }
};

int main() {

    int n1;
    cin >> n1;
    vector<int> nums1(n1);
    for (int i = 0; i < n1; i++) {
        cin >> nums1.at(i);
    }

    int n2;
    cin >> n2;
    vector<int> nums2(n2);
    for (int i = 0; i < n2; i++) {
        cin >> nums2.at(i);
    }

    Solution sol;
    vector<int> ans;
    ans = sol.intersect(nums1, nums2);

    for (int i = 0; i < ans.size(); i++) {
        cout << ans.at(i) << ' ';
    }
    cout << endl;

    return 0;
  
}

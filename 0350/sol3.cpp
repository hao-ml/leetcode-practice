#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;

        int i = 0;
  int j = 0;
  int k = 0;
  
  sort(nums1.begin(), nums1.end());
  sort(nums2.begin(), nums2.end());

  while (i < nums1.size() && j < nums2.size()) {
    if (nums1.at(i) < nums2.at(j)) {
      i++;
    }
    else if (nums1.at(i) > nums2.at(j)) {
      j++;
    }
    else {
      ans.push_back(nums1.at(i));
      i++;
      j++;
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

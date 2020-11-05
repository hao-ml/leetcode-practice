#include <bits/stdc++.h>
using namespace std;

// Definition for a Node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {        
        if (!root) return "[]";

        queue<TreeNode*> q;
        vector<string> v;

        q.push(root);
        v.push_back(to_string(root->val));
        while (!q.empty()) {
            TreeNode *thisNode = q.front();
            q.pop();
            if (thisNode->left) {
                q.push(thisNode->left);
                v.push_back(to_string(thisNode->left->val));
            }
            else v.push_back("null");

            if (thisNode->right) {
                q.push(thisNode->right);
                v.push_back(to_string(thisNode->right->val));
            }
            else v.push_back("null");
        }

        int iEnd = v.size() - 1;
        while (v.at(iEnd) == "null") iEnd--;

        string ans = "[";
        for (int i = 0; i < iEnd; i++) ans += v.at(i) + ",";
        ans += v.at(iEnd) + "]";

        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data == "[]") return nullptr;

        string s = data.substr(1, data.size()-2);
        string delimiter = ",";
        vector<string> v;
        auto start = 0U;
        auto end = s.find(delimiter);
        while (end != string::npos) {
            v.push_back(s.substr(start, end - start));
            start = end + 1;
            end = s.find(delimiter, start);
        }
        v.push_back(s.substr(start, end - start));
        
        auto i = 0U;
        TreeNode *root = new TreeNode(stoi(v.at(i)));
        TreeNode *curr = nullptr;
        queue<TreeNode*> q;
        q.push(root);
        i++;
        while(i < v.size()) {
            curr = q.front();
            q.pop();
            if (v.at(i) != "null") {
                TreeNode *left = new TreeNode(stoi(v.at(i)));
                curr->left = left;
                q.push(left);
            }
            i++;
            if (i == v.size()) break;
            if (v.at(i) != "null") {
                TreeNode *right = new TreeNode(stoi(v.at(i)));
                curr->right = right;
                q.push(right);
            }
            i++;
        }

        return root;
    }
};

int main() {

    // string data = "[1,2,3,null,null,4,5]";
    string data = "[1,2]";
    Codec sol;
    auto root = sol.deserialize(data);
    cout << sol.serialize(root) << endl;

    return 0;
}
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
        ostringstream out;
        serialize(root, out);

        return out.str();
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        istringstream in(data);        
        return deserialize(in);
    }

private:

    void serialize(TreeNode *root, ostringstream &out) {
        if (root) {
            out << root->val << ' ';
            serialize(root->left, out);
            serialize(root->right, out);
        }
        else {
            out << "null ";
        }
    }

    TreeNode* deserialize(istringstream &in) {
        string val;
        in >> val;
        if (val == "null") return nullptr;
        TreeNode *root = new TreeNode(stoi(val));
        root->left = deserialize(in);
        root->right = deserialize(in);
        return root;
    }

};

int main() {

    // string data = "[1,2,3,null,null,4,5]";
    // string data = "[1,2]";
    // Codec sol;
    // auto root = sol.deserialize(data);
    // cout << sol.serialize(root) << endl;

    return 0;
}
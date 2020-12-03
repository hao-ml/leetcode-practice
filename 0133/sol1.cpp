#include <bits/stdc++.h>
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (!node) return nullptr;
        Node *first = new Node(node->val);
        stack<Node*> stk;
        unordered_map<Node*, Node*> mp;
        unordered_set<Node*> visited;
        stk.push(node);
        mp.insert({node, first});
        while(!stk.empty()) {
            auto cur = stk.top(); stk.pop();
            if (visited.count(cur)) continue;
            auto cl = mp.at(cur); 
            for (int i = 0; i < cur->neighbors.size(); i++) {
                Node *nb = new Node();
                if (!mp.count(cur->neighbors.at(i))) {
                    nb->val = cur->neighbors.at(i)->val;
                    mp.insert({cur->neighbors.at(i), nb});
                }
                else nb = mp.at(cur->neighbors.at(i));
                cl->neighbors.push_back(nb);
                stk.push(cur->neighbors.at(i));
            }
            visited.insert(cur);
        }

        return first;
    }
};

int main() {
    Solution sol;

    return 0;
} 
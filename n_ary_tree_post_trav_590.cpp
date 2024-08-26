// 590. N-ary Tree Postorder Traversal

#include <bits/stdc++.h>

using namespace std;

class Node
{
public:
    int val;
    vector<Node *> children;

    Node() {}

    Node(int _val) { val = _val; }

    Node(int _val, vector<Node *> _children)
    {
        val = _val;
        children = _children;
    }
};

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
    vector<int> res;
    void dfs(Node *root)
    {
        if (!root)
            return;
        for (auto ch : root->children)
            dfs(ch);
        res.push_back(root->val);
        return;
    }

public:
    vector<int> postorder(Node *root)
    {
        dfs(root);
        return res;
    }
};
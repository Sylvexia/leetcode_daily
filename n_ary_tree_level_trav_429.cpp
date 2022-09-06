// 429. N-ary Tree Level Order Traversal

#include <bits/stdc++.h>

using namespace std;

class Node
{
public:
    int val;
    vector<Node *> children;

    Node() {}

    Node(int _val)
    {
        val = _val;
    }

    Node(int _val, vector<Node *> _children)
    {
        val = _val;
        children = _children;
    }
};

class Solution
{
public:
    vector<vector<int>> levelOrder(Node *root)
    {
        if (!root)
            return {};

        queue<Node *> q;
        vector<vector<int>> res;

        q.push(root);

        while (!q.empty())
        {
            res.push_back({});
            for (int i = q.size(); i > 0; i--)
            {
                Node *curr = q.front();
                q.pop();

                res.back().push_back(curr->val);

                for (auto *child : curr->children)
                    q.push(child);
            }
        }

        return res;
    }
};
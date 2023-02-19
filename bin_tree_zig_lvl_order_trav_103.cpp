// 103. Binary Tree Zigzag Level Order Traversal

#include <bits/stdc++.h>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        if (!root)
            return {};

        queue<TreeNode *> q;

        q.push(root);

        vector<vector<int>> res;
        bool is_left = false;

        while (!q.empty())
        {
            int q_counter = q.size();
            vector<int> row;
            while (q_counter--)
            {
                TreeNode *todo = q.front();
                q.pop();

                if (todo->left)
                    q.push(todo->left);
                if (todo->right)
                    q.push(todo->right);

                row.push_back(todo->val);
            }

            if (is_left)
                reverse(row.begin(), row.end());

            is_left = !(is_left);
            res.push_back(row);
        }

        return res;
    }
};
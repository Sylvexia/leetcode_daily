// 958. Check Completeness of a Binary Tree

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
    bool isCompleteTree(TreeNode *root)
    {
        queue<TreeNode *> q;
        bool has_pre = true;
        q.push(root);

        while (!q.empty())
        {
            TreeNode *node_front = q.front();
            q.pop();

            if (!node_front)
                has_pre = false;
            else
            {
                if (not has_pre)
                    return false;

                q.push(node_front->left);
                q.push(node_front->right);
            }
        }

        return true;
    }
};
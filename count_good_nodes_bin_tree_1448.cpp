// 1448. Count Good Nodes in Binary Tree

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
    int res{};
    int goodNodes(TreeNode *root)
    {
        pre(root, INT_MIN);
        return res;
    }

    void pre(TreeNode *root, int max)
    {
        if (!root)
            return;
        if (root->val >= max)
        {
            res++;
            max = root->val;
        }
        pre(root->left, max);
        pre(root->right, max);
    }
};
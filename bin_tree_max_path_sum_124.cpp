// 124. Binary Tree Maximum Path Sum

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
    int gain(TreeNode *root, int &res)
    {
        if (!root)
            return 0;

        int l{max(gain(root->left, res), 0)};
        int r{max(gain(root->right, res), 0)};
        int cur{root->val + r + l};
        res = max(res, cur);
        return root->val + max(l, r);
    }

public:
    int maxPathSum(TreeNode *root)
    {
        int res{INT_MIN};
        gain(root, res);
        return res;
    }
};
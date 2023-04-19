// 1372. Longest ZigZag Path in a Binary Tree

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

// left = 1 , right = 2

class Solution
{
    void dfs(TreeNode *root, int l, int r, int &res)
    {
        if (!root)
            return;
        res = max({res, l, r});
        dfs(root->left, 0, l + 1, res);
        dfs(root->right, r + 1, 0, res);
        return;
    }

public:
    int longestZigZag(TreeNode *root)
    {
        int res = 0;
        dfs(root, 0, 0, res);
        return res;
    }
};
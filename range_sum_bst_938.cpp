// 938. Range Sum of BST

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
    void dfs(TreeNode *root, const int low, const int high, int &res)
    {
        if (!root)
            return;
        int val = root->val;
        if (low <= val && val <= high)
            res += val;
        if (low < val)
            dfs(root->left, low, high, res);
        if (val < high)
            dfs(root->right, low, high, res);
    }
    int rangeSumBST(TreeNode *root, int low, int high)
    {
        int res = 0;
        dfs(root, low, high, res);
        return res;
    }
};
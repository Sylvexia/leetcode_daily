// 530. Minimum Absolute Difference in BST

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
    void dfs(TreeNode *root, int &prev_val, int &diff)
    {
        if (!root)
            return;

        dfs(root->left, prev_val, diff);

        if (prev_val >= 0)
            diff = min(diff, root->val - prev_val);

        prev_val = root->val;

        dfs(root->right, prev_val, diff);
    }

public:
    int getMinimumDifference(TreeNode *root)
    {
        int diff = INT_MAX, prev_val = -1;

        dfs(root, prev_val, diff);

        return diff;
    }
};
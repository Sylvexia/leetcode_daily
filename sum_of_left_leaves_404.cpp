// 404. Sum of Left Leaves

#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right)
    {
    }
};

class Solution
{
    int dfs(TreeNode *root)
    {
        if (!root)
            return 0;

        int val = 0;
        if (root->left and !(root->left->left) and !(root->left->right)) {
            val += root->left->val;
        }

        return dfs(root->left) + dfs(root->right) + val;
    }

public:
    int sumOfLeftLeaves(TreeNode *root) {
        return dfs(root);
    }
};
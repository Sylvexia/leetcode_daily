// 2331. Evaluate Boolean Binary Tree

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

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
    bool dfs(TreeNode *root)
    {
        if (!root->left and !root->right)
            return (root->val == 1);

        bool left = dfs(root->left);
        bool right = dfs(root->right);
        if (root->val == 2)
            return left | right;
        else if (root->val == 3)
            return left & right;

        return false;
    }

public:
    bool evaluateTree(TreeNode *root) { return dfs(root); }
};
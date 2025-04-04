// 1123. Lowest Common Ancestor of Deepest Leaves

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
    pair<TreeNode *, int> dfs(TreeNode *root)
    {
        if (!root)
            return {nullptr, 0};

        auto [leftNode, leftDepth] = dfs(root->left);
        auto [rightNode, rightDepth] = dfs(root->right);

        if (leftDepth > rightDepth)
            return {leftNode, leftDepth + 1};
        if (rightDepth > leftDepth)
            return {rightNode, rightDepth + 1};

        return {root, leftDepth + 1};
    }

public:
    TreeNode *lcaDeepestLeaves(TreeNode *root) { return dfs(root).first; }
};
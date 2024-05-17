// 1325. Delete Leaves With a Given Value

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
    bool dfs(TreeNode *root, int target)
    {
        if (!root)
            return false;
        if (dfs(root->left, target))
            root->left = nullptr;
        if (dfs(root->right, target))
            root->right = nullptr;
        if (!root->left && !root->right && root->val == target)
            return true;
        return false;
    }

public:
    TreeNode *removeLeafNodes(TreeNode *root, int target)
    {
        TreeNode dummy(INT_MIN, root, nullptr);
        dfs(&dummy, target);
        return dummy.left;
    }
};
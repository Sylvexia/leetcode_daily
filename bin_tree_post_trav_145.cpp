// 145. Binary Tree Postorder Traversal

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
    vector<int> res;
    void dfs(TreeNode *root)
    {
        if (!root)
            return;
        dfs(root->left);
        dfs(root->right);
        res.push_back(root->val);
    }

public:
    vector<int> postorderTraversal(TreeNode *root)
    {
        dfs(root);
        return res;
    }
};
// 94. Binary Tree Inorder Traversal

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
    vector<int> res{};
    void dfs(TreeNode *root)
    {
        if (!root)
            return;

        dfs(root->left);

        res.push_back(root->val);

        dfs(root->right);
    }
    vector<int> inorderTraversal(TreeNode *root)
    {
        dfs(root);
        return res;
    }
};
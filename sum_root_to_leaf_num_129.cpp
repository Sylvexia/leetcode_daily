// 129. Sum Root to Leaf Numbers

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
    int dfs(TreeNode *root, int p_val, vector<int> &mem)
    {
        if (!root)
            return 0;

        int cur = p_val * 10 + root->val;

        if (!root->left and !root->right)
        {
            mem.push_back(cur);
        }

        dfs(root->left, cur, mem);
        dfs(root->right, cur, mem);

        return 0;
    }

public:
    int sumNumbers(TreeNode *root)
    {
        vector<int> mem;
        dfs(root, 0, mem);
        return accumulate(mem.begin(), mem.end(), 0);
    }
};

class Solution
{
    int dfs(TreeNode *root, int p_val)
    {
        if (!root)
            return 0;

        int cur = p_val * 10 + root->val;

        if (!root->left and !root->right)
            return cur;

        return dfs(root->left, cur) + dfs(root->right, cur);
    }

public:
    int sumNumbers(TreeNode *root)
    {
        return dfs(root, 0);
    }
};
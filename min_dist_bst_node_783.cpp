// 783. Minimum Distance Between BST Nodes

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
    void dfs(TreeNode *root, vector<int> &vals)
    {
        if (!root)
            return;
        vals.push_back(root->val);
        dfs(root->left, vals);
        dfs(root->right, vals);
    }

public:
    int minDiffInBST(TreeNode *root)
    {
        vector<int> vals;
        dfs(root, vals);

        sort(vals.begin(), vals.end());
        int res = INT_MAX;

        for (int i = 0; i < vals.size() - 1; i++)
            res = min(res, vals[i + 1] - vals[i]);

        return res;
        
    }
};
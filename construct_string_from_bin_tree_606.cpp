// 606. Construct String from Binary Tree

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
    string res;
    void dfs(TreeNode *root, string &res)
    {
        if (!root)
            return;
        res.append(to_string(root->val));
        if (root->left)
        {
            res.push_back('(');
            dfs(root->left, res);
            res.push_back(')');
        }
        else if (root->right)
            res += "()";
        if (root->right)
        {
            res.push_back('(');
            dfs(root->right, res);
            res.push_back(')');
        }
    }
    string tree2str(TreeNode *root)
    {
        dfs(root, res);
        return res;
    }
};
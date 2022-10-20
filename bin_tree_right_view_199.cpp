// 199. Binary Tree Right Side View

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
    void rightView(TreeNode *root, vector<int> &vec, int level)
    {
        if (!root)
            return;

        if (vec.size() < level)
        {
            vec.push_back(root->val);
        }

        rightView(root->right, vec, level + 1);
        rightView(root->left, vec, level + 1);
    }
    vector<int> rightSideView(TreeNode *root)
    {
        vector<int> res;
        rightView(root, res, 1);
        return res;
    }
};
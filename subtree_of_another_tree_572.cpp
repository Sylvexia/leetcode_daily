// 572. Subtree of Another Tree

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
    bool isSametree(TreeNode *p, TreeNode *q)
    {
        if (!p && !q)
            return true;

        if (!p || !q)
            return false;

        return (p->val == q->val) &&
               isSametree(p->left, q->left) &&
               isSametree(p->right, q->right);
    }

public:
    bool isSubtree(TreeNode *root, TreeNode *subRoot)
    {
        if (!root)
            return false;

        return ((root->val == subRoot->val) && isSametree(root, subRoot)) ||
               isSubtree(root->left, subRoot) ||
               isSubtree(root->right, subRoot);
    }
};
// 222. Count Complete Tree Nodes

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

int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
    int helper(TreeNode *root)
    {
        if (!root)
            return 0;
        int l = 0, r = 0;
        TreeNode *left = root, *right = root;
        while (left) {
            left = left->left;
            l++;
        }
        while (right) {
            right = right->right;
            r++;
        }
        if (l == r)
            return (1 << l) - 1;
        return 1 + helper(root->left) + helper(root->right);
    }

public:
    int countNodes(TreeNode *root) { return helper(root); }
};

class Solution
{
public:
    int countNodes(TreeNode *root)
    {
        if (!root)
            return 0;
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};
// 1038. Binary Search Tree to Greater Sum Tree

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

void dfs(TreeNode *root, int &sum)
{
    if (!root)
        return;
    dfs(root->right, sum);
    root->val += sum;
    sum = root->val;
    dfs(root->left, sum);
}

class Solution
{
public:
    TreeNode *bstToGst(TreeNode *root)
    {
        int sum = 0;
        dfs(root, sum);
        return root;
    }
};
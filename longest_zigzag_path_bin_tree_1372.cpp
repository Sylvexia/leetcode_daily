// 1372. Longest ZigZag Path in a Binary Tree

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
    void dfs(TreeNode *root, int l, int r, int &res)
    {
        if (!root)
            return;
        res = max({res, l, r});
        dfs(root->left, 0, l + 1, res);
        dfs(root->right, r + 1, 0, res);
        return;
    }

public:
    int longestZigZag(TreeNode *root)
    {
        int res = 0;
        dfs(root, 0, 0, res);
        return res;
    }
};

class Solution
{
    int dfs(TreeNode *root, int dir) // left=1, right=2
    {
        if (!root)
            return 0;

        int left = dfs(root->left, 1);
        int right = dfs(root->right, 2);
        if (dir == 1)
            return max(right + 1, left);
        else if (dir == 2)
            return max(left + 1, right);
        return 0;
    }

public:
    int longestZigZag(TreeNode *root)
    {
        return max(dfs(root->left, 1), dfs(root->right, 2));
    }
}; // this does not work!
// You have to check if you are in the bottom of the tree to know the answer

class Solution
{
public:
    int dfs(TreeNode *root, bool isLeft, int cnt)
    {
        if (!root)
            return cnt;
        if (isLeft)
            return max(dfs(root->right, 0, cnt + 1), dfs(root->left, 1, 0));
        return max(dfs(root->left, 1, cnt + 1), dfs(root->right, 0, 0));
    }
    int longestZigZag(TreeNode *root)
    {
        return max(dfs(root->left, true, 0), dfs(root->right, false, 0));
    }
};
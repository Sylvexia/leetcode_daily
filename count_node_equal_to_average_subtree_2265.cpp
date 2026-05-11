// 2265. Count Nodes Equal to Average of Subtree

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

#include <bits/stdc++.h>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
    int res;
    pair<int, int> dfs(TreeNode *root)
    {
        if (!root)
            return {0, 0};
        auto [count_left, sum_left] = dfs(root->left);
        auto [count_right, sum_right] = dfs(root->right);

        int curCount = 1 + count_left + count_right;
        int curSum = root->val + sum_left + sum_right;

        if (curSum / curCount == root->val)
            res++;

        return {curCount, curSum};
    }

public:
    int averageOfSubtree(TreeNode *root)
    {
        res = 0;
        dfs(root);
        return res;
    }
};
// 113. Path Sum II

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

class Solution
{
    vector<vector<int>> res;
    void dfs(TreeNode *root, int target, vector<int> &gen)
    {
        if (!root)
            return;
        int val = root->val;
        target -= val;
        gen.push_back(val);
        if (target == 0 and !root->left and !root->right) {
            res.push_back(gen);
        }

        dfs(root->left, target, gen);
        dfs(root->right, target, gen);

        gen.pop_back();
    }

public:
    vector<vector<int>> pathSum(TreeNode *root, int targetSum)
    {
        vector<int> gen;
        dfs(root, targetSum, gen);
        return res;
    }
};
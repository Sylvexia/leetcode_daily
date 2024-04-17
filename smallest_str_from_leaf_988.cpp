// 988. Smallest String Starting From Leaf

#include <bits/stdc++.h>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();


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

class Solution
{
    string res;

    void dfs(TreeNode *root, string gen)
    {
        if (!root)
            return;

        gen = char(root->val + 'a') + gen;

        if (!root->left and !root->right) {
            res = min(res, gen);
        }

        dfs(root->left, gen);
        dfs(root->right, gen);
    }

public:
    string smallestFromLeaf(TreeNode *root)
    {
        res = "~";
        dfs(root, "");
        return res;
    }
};
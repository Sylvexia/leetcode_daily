// 1261. Find Elements in a Contaminated Binary Tree

#include <bits/stdc++.h>
#include <unordered_set>

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

class FindElements
{
    unordered_set<int> u_set;
    void dfs(TreeNode *root, int val)
    {
        if (!root)
            return;

        root->val = val;
        u_set.insert(val);

        dfs(root->left, val * 2 + 1);
        dfs(root->right, val * 2 + 2);
    }

public:
    FindElements(TreeNode *root) { dfs(root, 0); }

    bool find(int target) { return u_set.count(target); }
};
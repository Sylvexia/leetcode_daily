// 1110. Delete Nodes And Return Forest

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
    vector<TreeNode *> res;
    set<int> del_set;
    TreeNode *dfs(TreeNode *node, bool is_root)
    {
        if (!node)
            return nullptr;

        bool deleted = del_set.find(node->val) != del_set.end();
        if (is_root and !deleted)
            res.push_back(node);

        node->left = dfs(node->left, deleted);
        node->right = dfs(node->right, deleted);

        return deleted ? nullptr : node;
    }

public:
    vector<TreeNode *> delNodes(TreeNode *root, vector<int> &to_delete)
    {
        for (int ele : to_delete)
            del_set.insert(ele);
        dfs(root, true);
        return res;
    }
};
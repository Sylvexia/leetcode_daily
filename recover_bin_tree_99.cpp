// 99. Recover Binary Search Tree

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

#include <iostream>
#include <vector>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
    vector<int> vals;
    int i = 0;
    void trav(TreeNode *root)
    {
        if (!root)
            return;
        trav(root->left);
        vals.push_back(root->val);
        trav(root->right);
    }
    void rebuild(TreeNode *root)
    {
        if (!root)
            return;
        rebuild(root->left);
        root->val = vals[i++];
        rebuild(root->right);
    }

public:
    void recoverTree(TreeNode *root)
    {
        trav(root);
        ranges::sort(vals);
        rebuild(root);
    }
};
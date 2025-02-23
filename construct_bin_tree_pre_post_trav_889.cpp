// 889. Construct Binary Tree from Preorder and Postorder Traversal

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
    int pre_i = 0;
    int pos_i = 0;

public:
    TreeNode *constructFromPrePost(vector<int> &preorder,
                                   vector<int> &postorder)
    {
        TreeNode *root = new TreeNode(preorder[pre_i++]);
        if (root->val != postorder[pos_i])
            root->left = constructFromPrePost(preorder, postorder);
        if (root->val != postorder[pos_i])
            root->right = constructFromPrePost(preorder, postorder);
        pos_i++;
        return root;
    }
};
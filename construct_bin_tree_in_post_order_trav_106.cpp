// 106. Construct Binary Tree from Inorder and Postorder Traversal

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
    TreeNode *build(vector<int> &inorder, vector<int> &postorder,
                    int in_start, int in_end, unordered_map<int, int> &inorder_i, int &postIdx)
    {
        if (in_start > in_end)
            return nullptr;

        TreeNode *ret = new TreeNode(postorder[postIdx--]);
        int inIdx = inorder_i[ret->val];
        ret->right = build(inorder, postorder, inIdx + 1, in_end, inorder_i, postIdx);
        ret->left = build(inorder, postorder, in_start, inIdx - 1, inorder_i, postIdx);

        return ret;
    }

public:
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {
        unordered_map<int, int> inorder_i;
        int postIdx = inorder.size() - 1;
        for (int i = 0; i < inorder.size(); i++)
            inorder_i[inorder[i]] = i;

        return build(inorder, postorder, 0, postorder.size() - 1, inorder_i, postIdx);
    }
};
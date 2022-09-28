// 105. Construct Binary Tree from Preorder and Inorder Traversal

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
public:
    // root_index:prorder
    // pivot:inorder
    TreeNode *build(vector<int> &preorder, vector<int> &inorder, int &root_index, int left, int right)
    {
        if (left > right)
            return nullptr;
        int pivot = left; // inorder

        while (inorder[pivot] != preorder[root_index])
            pivot++;

        root_index++; // preorder

        TreeNode *new_node = new TreeNode(inorder[pivot]);
        new_node->left = build(preorder, inorder, root_index, left, pivot - 1);
        new_node->right = build(preorder, inorder, root_index, pivot + 1, right);

        return new_node;
    }

    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        int root_index = 0;
        return build(preorder, inorder, root_index, 0, preorder.size() - 1);
    }
};
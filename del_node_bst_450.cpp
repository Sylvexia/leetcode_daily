// 450. Delete Node in a BST

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

class Solution
{
public:
    TreeNode *deleteNode(TreeNode *root, int key)
    {
        if (!root)
            return root;

        if (key < root->val)
            root->left = deleteNode(root->left, key);
        else if (key > root->val)
            root->right = deleteNode(root->right, key);
        else {
            if (!root->left)
                return root->right;
            else if (!root->right)
                return root->left;
            else {
                TreeNode *min_node = root->right;
                while (min_node->left)
                    min_node = min_node->left;
                root->val = min_node->val;
                root->right = deleteNode(root->right, root->val);
            }
        }
        return root;
    }
};
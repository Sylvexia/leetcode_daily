// 230. Kth Smallest Element in a BST

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
    int smallest{};

public:
    void findsmallest(TreeNode *root, int &k)
    {
        if (!root)
            return;

        findsmallest(root->left, k);

        k--;
        if (k == 0)
        {
            smallest = root->val;
            return;
        }

        findsmallest(root->right, k);
    }
    int kthSmallest(TreeNode *root, int k)
    {
        findsmallest(root, k);
        return smallest;
    }
};
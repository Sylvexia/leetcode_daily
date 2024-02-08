// 437. Path Sum III

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
    int sumUp(TreeNode *root, long long int pre, int sum)
    {
        if (!root)
            return 0;
        long long int cur = pre + root->val;
        return (cur == sum) + sumUp(root->left, cur, sum) +
               sumUp(root->right, cur, sum);
    }

public:
    int pathSum(TreeNode *root, int targetSum)
    {
        if (!root)
            return 0;
        return sumUp(root, 0, targetSum) + pathSum(root->left, targetSum) +
               pathSum(root->right, targetSum);
    }
};
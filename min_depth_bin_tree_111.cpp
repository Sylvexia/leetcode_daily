// 111. Minimum Depth of Binary Tree

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
public:
    int minDepth(TreeNode *root)
    {
        if (!root)
            return 0;
        int left = minDepth(root->left);
        int right = minDepth(root->right);
        return (left == 0 or right == 0) ? left + right + 1
                                         : min(left, right) + 1;
    }
};
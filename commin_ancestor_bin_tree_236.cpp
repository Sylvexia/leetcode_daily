// 236. Lowest Common Ancestor of a Binary Tree

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution
{
public:
    TreeNode *lowestCommonAncestor(TreeNode *node, TreeNode *p, TreeNode *q)
    {
        if (!node || node == p || node == q)
            return node;
        TreeNode *left = lowestCommonAncestor(node->left, p, q);
        TreeNode *right = lowestCommonAncestor(node->right, p, q);
        return !left    ? right
               : !right ? left
                        : node;
    }
};
// 98. Validate Binary Search Tree

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
    bool isValidBST(TreeNode *root)
    {
        return search(root, nullptr, nullptr);
    }
    bool search(TreeNode *node, TreeNode *min, TreeNode *max)
    {
        if (!node)
            return true;

        if ((min && node->val <= min->val) || (max && node->val >= max->val))
            return false;

        return (search(node->left, min, node) && search(node->right, node, max));
    }
};
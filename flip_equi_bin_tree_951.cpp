// 951. Flip Equivalent Binary Trees

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
    bool dfs(TreeNode *root1, TreeNode *root2)
    {
        if (!root1 and !root2)
            return true;
        if (!root1 or !root2)
            return false;
        if (root1->val != root2->val)
            return false;
        
        bool noSwap =
            dfs(root1->left, root2->left) and dfs(root1->right, root2->right);
        bool swap =
            dfs(root1->right, root2->left) and dfs(root1->left, root2->right);

        return noSwap || swap;
    }

public:
    bool flipEquiv(TreeNode *root1, TreeNode *root2)
    {
        return dfs(root1, root2);
    }
};
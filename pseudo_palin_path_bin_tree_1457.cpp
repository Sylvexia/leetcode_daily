// 1457. Pseudo-Palindromic Paths in a Binary Tree

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

    int res{};
    array<int, 10> count = {0};

public:
    int pseudoPalindromicPaths(TreeNode *root)
    {
        dfs(root);
        return res;
    }

    void dfs(TreeNode *root)
    {
        if (!root)
            return;

        count[root->val]++;

        if (!root->left && !root->right)
        {
            int odd{};
            for (int i = 0; i < 10; i++)
            {
                if (count[i] % 2 == 1)
                {
                    odd++;
                    if (odd > 1)
                        break;
                }
            }
            if (odd <= 1)
                res++;
        }
        dfs(root->left);
        dfs(root->right);
        count[root->val]--;
    }
};
// 637. Average of Levels in Binary Tree

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
    vector<double> averageOfLevels(TreeNode *root)
    {
        vector<double> res;
        queue<TreeNode *> q;
        q.push(root);

        while (!q.empty())
        {
            long total = 0;
            int q_size = q.size();

            for (int i = 0; i < q_size; i++)
            {
                TreeNode *node = q.front();
                q.pop();

                if (node->left)
                    q.push(node->left);

                if (node->right)
                    q.push(node->right);

                total += node->val;
            }
            res.push_back((double)total / q_size);
        }
        return res;
    }
};
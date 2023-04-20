// 662. Maximum Width of Binary Tree

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
    int widthOfBinaryTree(TreeNode *root)
    {
        queue<pair<TreeNode *, int>> q;
        q.push({root, 0});
        int res = 1;

        while (!q.empty())
        {
            int qsize = q.size();

            int start = q.front().second;
            int end = q.back().second;

            res = max(res, end - start + 1);

            for (int i = 0; i < qsize; i++)
            {
                auto [front_node, front_idx] = q.front();
                q.pop();
                unsigned int cal_idx = front_idx - start;
                if (front_node->left)
                    q.push({front_node->left, 2 * cal_idx + 1});
                if (front_node->right)
                    q.push({front_node->right, 2 * cal_idx + 2});
            }
        }
        return res;
    }
};
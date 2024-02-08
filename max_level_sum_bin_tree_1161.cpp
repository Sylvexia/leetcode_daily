// 1161. Maximum Level Sum of a Binary Tree

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
    int maxLevelSum(TreeNode *root)
    {
        int max_sum = INT_MIN;
        int max_level = -1;
        int cur_level = 1;
        queue<TreeNode *> q;
        q.push(root);

        while (!q.empty()) {
            size_t q_size = q.size();
            int level_sum = 0;
            for (int i = 0; i < q_size; i++) {
                TreeNode *front = q.front();
                level_sum += front->val;
                if (front->left)
                    q.push(front->left);
                if (front->right)
                    q.push(front->right);
                q.pop();
            }
            if (level_sum > max_sum) {
                max_sum = level_sum;
                max_level = cur_level;
            }
            cur_level++;
        }

        return max_level;
    }
};
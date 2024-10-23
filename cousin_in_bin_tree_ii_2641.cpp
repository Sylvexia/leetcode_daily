// 2641. Cousins in Binary Tree II

#include <bits/stdc++.h>
#include <numeric>

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
public:
    TreeNode *replaceValueInTree(TreeNode *root)
    {
        queue<TreeNode *> q;
        vector<int> level_sums;
        q.push(root);
        while (!q.empty()) {
            int q_size = q.size();
            int level_sum = 0;
            for (int i = 0; i < q_size; i++) {
                auto front = q.front();
                q.pop();
                level_sum += front->val;
                if (front->left) {
                    q.push(front->left);
                }
                if (front->right) {
                    q.push(front->right);
                }
            }
            level_sums.push_back(level_sum);
        }

        q.push(root);
        root->val = 0;
        int level_index = 1;
        while (!q.empty()) {
            int q_size = q.size();
            for (int i = 0; i < q_size; i++) {
                auto front = q.front();
                q.pop();
                int child_sum = 0;

                if (front->left)
                    child_sum += front->left->val;
                if (front->right)
                    child_sum += front->right->val;

                if (front->left) {
                    front->left->val = level_sums[level_index] - child_sum;
                    q.push(front->left);
                }
                if (front->right) {
                    front->right->val = level_sums[level_index] - child_sum;
                    q.push(front->right);
                }
            }
            level_index++;
        }
        return root;
    }
};
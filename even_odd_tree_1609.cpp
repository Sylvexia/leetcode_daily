// 1609. Even Odd Tree

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
public:
    bool isEvenOddTree(TreeNode *root)
    {
        queue<TreeNode *> q;
        int level = 0;
        q.push(root);
        while (!q.empty()) {
            int q_size = q.size();
            int prev = (level % 2 == 1) ? 1000002 : -1;
            for (int i = 0; i < q_size; i++) {
                TreeNode *front = q.front();
                q.pop();
                if (level % 2 == 1) {
                    if (front->val % 2 == 1 or prev <= front->val)
                        return false;
                } else {
                    if (front->val % 2 == 0 or prev >= front->val)
                        return false;
                }
                prev = front->val;
                if (front->left)
                    q.push(front->left);
                if (front->right)
                    q.push(front->right);
            }
            level++;
        }
        return true;
    }
};
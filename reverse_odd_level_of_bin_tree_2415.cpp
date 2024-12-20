// 2415. Reverse Odd Levels of Binary Tree

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
    TreeNode *reverseOddLevels(TreeNode *root)
    {
        if (!root)
            return nullptr;
        queue<TreeNode *> q;
        q.push(root);
        int level = 0;

        while (q.size()) {
            int qsize = q.size();
            vector<TreeNode *> vec;
            for (int i = 0; i < qsize; i++) {
                auto front = q.front();
                q.pop();
                vec.push_back(front);
                if (front->left)
                    q.push(front->left);
                if (front->right)
                    q.push(front->right);
            }
            if (level % 2 == 1) {
                int l = 0, r = vec.size() - 1;
                while (l < r) {
                    swap(vec[l]->val, vec[r]->val);
                    l++;
                    r--;
                }
            }
            level++;
        }
        return root;
    }
};
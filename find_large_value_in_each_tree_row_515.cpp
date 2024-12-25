// 515. Find Largest Value in Each Tree Row

#include <bits/stdc++.h>
#include <climits>

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
    vector<int> largestValues(TreeNode *root)
    {
        if (!root)
            return {};
        queue<TreeNode *> q;
        q.push(root);
        vector<int> res;
        while (q.size()) {
            int qsize = q.size();
            int curMax = INT_MIN;
            for (int i = 0; i < qsize; i++) {
                auto front = q.front();
                q.pop();
                curMax = max(curMax, front->val);

                if (front->left)
                    q.push(front->left);
                if (front->right)
                    q.push(front->right);
            }
            res.push_back(curMax);
        }
        return res;
    }
};
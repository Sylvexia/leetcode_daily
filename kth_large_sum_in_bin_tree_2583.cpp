// 2583. Kth Largest Sum in a Binary Tree

#include <bits/stdc++.h>
#include <queue>

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
    long long kthLargestLevelSum(TreeNode *root, int k)
    {
        priority_queue<long long> pq;
        queue<TreeNode *> q;
        q.push(root);
        int level = 0;
        while (!q.empty()) {
            level++;
            int q_size = q.size();
            long long level_sum = 0;
            for (int i = 0; i < q_size; i++) {
                auto cur = q.front();
                auto cur_val = cur->val;
                q.pop();

                level_sum += cur_val;
                if (cur->left)
                    q.push(cur->left);
                if (cur->right)
                    q.push(cur->right);
            }
            pq.push(level_sum);
        }
        if (level < k)
            return -1;
        long long res = -1;
        while (k) {
            res = pq.top();
            pq.pop();
            k--;
        }
        return res;
    }
};
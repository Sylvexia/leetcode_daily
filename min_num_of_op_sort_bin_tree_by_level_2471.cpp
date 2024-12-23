// 2471. Minimum Number of Operations to Sort a Binary Tree by Level

#include <bits/stdc++.h>
#include <queue>
#include <unordered_map>

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
    int sortSwapNum(vector<int> &vec)
    {
        int res = 0;
        auto sorted = vec;
        sort(sorted.begin(), sorted.end());

        unordered_map<int, int> u_map;
        for (int i = 0; i < vec.size(); i++) {
            u_map[vec[i]] = i;
        }

        for (int i = 0; i < vec.size(); i++) {
            if (vec[i] == sorted[i])
                continue;
            res++;
            int cur = u_map[sorted[i]];
            u_map[vec[i]] = cur;
            swap(vec[cur], vec[i]);
        }
        return res;
    }

public:
    int minimumOperations(TreeNode *root)
    {
        queue<TreeNode *> q;
        q.push(root);
        int res = 0;
        while (q.size()) {
            int qsize = q.size();
            vector<int> vec;

            for (int i = 0; i < qsize; i++) {
                auto front = q.front();
                q.pop();

                vec.push_back(front->val);
                if (front->left)
                    q.push(front->left);
                if (front->right)
                    q.push(front->right);
            }
            res += sortSwapNum(vec);
        }
        return res;
    }
};
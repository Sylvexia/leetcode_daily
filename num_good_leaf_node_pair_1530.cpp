// 1530. Number of Good Leaf Nodes Pairs

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
    int res = 0;
    vector<int> dfs(TreeNode *root, int distance)
    {
        if (!root)
            return {};
        auto left = dfs(root->left, distance);
        auto right = dfs(root->right, distance);

        vector<int> ret;
        if (left.size() == 0 and right.size() == 0) {
            ret.push_back(1);
            return ret;
        }

        for (int i = 0; i < left.size(); i++) {
            for (int j = 0; j < right.size(); j++) {
                if (left[i] + right[j] <= distance)
                    res++;
            }
        }

        for (auto ele : left)
            ret.push_back(ele + 1);
        for (auto ele : right)
            ret.push_back(ele + 1);

        return ret;
    }

public:
    int countPairs(TreeNode *root, int distance)
    {
        dfs(root, distance);
        return res;
    }
};
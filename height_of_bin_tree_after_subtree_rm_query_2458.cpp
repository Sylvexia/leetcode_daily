// 2458. Height of Binary Tree After Subtree Removal Queries

#include <bits/stdc++.h>
#include <algorithm>
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

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
    int getHight(TreeNode *node, unordered_map<TreeNode *, int> &heights)
    {
        if (!node)
            return -1;
        if (heights.count(node)) {
            return heights[node];
        }

        int res = 1 + max(getHight(node->left, heights),
                          getHight(node->right, heights));

        return heights[node] = res;
    }

    void dfs(TreeNode *node,
             int depth,
             int maxVal,
             unordered_map<int, int> &resMap,
             unordered_map<TreeNode *, int> &heights)
    {
        if (!node)
            return;

        resMap[node->val] = maxVal;

        dfs(node->left, depth + 1,
            max(maxVal, depth + 1 + getHight(node->right, heights)), resMap,
            heights);
        dfs(node->right, depth + 1,
            max(maxVal, depth + 1 + getHight(node->left, heights)), resMap,
            heights);
    }

public:
    vector<int> treeQueries(TreeNode *root, vector<int> &queries)
    {
        unordered_map<int, int> resMap;
        unordered_map<TreeNode *, int> heights;

        dfs(root, 0, 0, resMap, heights);

        int n = queries.size();
        vector<int> res(n);
        for (int i = 0; i < n; i++)
            res[i] = resMap[queries[i]];

        return res;
    }
};
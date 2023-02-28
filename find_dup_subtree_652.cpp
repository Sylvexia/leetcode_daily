// 652. Find Duplicate Subtrees

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
private:
    string serialize(TreeNode *node, unordered_map<string, vector<TreeNode *>> &u_map)
    {
        if (!node)
            return "";
        string s = "(" +
                   serialize(node->left, u_map) +
                   to_string(node->val) +
                   serialize(node->right, u_map) +
                   ")";

        u_map[s].push_back(node);
        return s;
    }

public:
    vector<TreeNode *> findDuplicateSubtrees(TreeNode *root)
    {
        unordered_map<string, vector<TreeNode *>> u_map;
        vector<TreeNode *> res;

        serialize(root, u_map);
        for (auto &[key, val] : u_map)
        {
            if (val.size() > 1)
                res.push_back(val[0]);
        }

        return res;
    }
};
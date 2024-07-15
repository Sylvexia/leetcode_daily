// 2196. Create Binary Tree From Descriptions

#include <bits/stdc++.h>
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
public:
    TreeNode *createBinaryTree(vector<vector<int>> &descriptions)
    {
        unordered_map<TreeNode *, TreeNode *> get_par;
        unordered_map<int, TreeNode *> get_node;

        for (auto &desc : descriptions) {
            int parent = desc[0];
            int child = desc[1];
            int is_left = desc[2];

            auto parent_node = get_node.count(parent)
                                   ? get_node[parent]
                                   : get_node[parent] = new TreeNode(parent);

            auto child_node = get_node.count(child)
                                  ? get_node[child]
                                  : get_node[child] = new TreeNode(child);

            if (is_left)
                parent_node->left = child_node;
            else
                parent_node->right = child_node;

            get_par[child_node] = parent_node;
        }

        auto root = get_node.begin()->second;
        while (get_par.count(root))
            root = get_par[root];
        return root;
    }
};
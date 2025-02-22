// 337. House Robber III

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
    unordered_map<TreeNode *, array<int, 2>> u_map;
    int dfs(TreeNode *root, bool canRob)
    {
        if (!root)
            return 0;

        if (u_map.count(root) and u_map[root][canRob] != -1)
            return u_map[root][canRob];

        u_map[root] = {-1, -1};
        int notRob = dfs(root->left, true) + dfs(root->right, true);
        int rob = canRob ? dfs(root->left, false) + dfs(root->right, false) +
                               root->val
                         : INT_MIN;

        return u_map[root][canRob] = max(rob, notRob);
    }

public:
    int rob(TreeNode *root) { return dfs(root, true); }
};
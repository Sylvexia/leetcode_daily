// 3319. K-th Largest Perfect Subtree Size in Binary Tree

#include <bits/stdc++.h>
#include <algorithm>
#include <functional>

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
    int kthLargestPerfectSubtree(TreeNode *root, int k)
    {
        vector<int> res;
        function<int(TreeNode *)> dfs = [&](TreeNode *root) -> int {
            if (!root)
                return 0;
            int l = dfs(root->left);
            int r = dfs(root->right);

            if (l == r and l >= 0) {
                res.push_back(l + 1);
                return l + 1;
            }

            return -1;
        };

        dfs(root);
        ranges::nth_element(res, res.end() - k);
        if (k <= res.size())
            return (1 << res[res.size() - k]) - 1;
        return -1;
    }
};
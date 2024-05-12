// 257. Binary Tree Paths

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
    vector<int> vec;
    vector<string> res;
    void dfs(TreeNode *root)
    {
        if (!root)
            return;

        vec.push_back(root->val);

        dfs(root->left);

        dfs(root->right);

        if (!root->left and !root->right) {
            string res_str;
            for (int i = 0; i < vec.size(); i++) {
                res_str.append(to_string(vec[i]));
                if (i != vec.size() - 1)
                    res_str.append("->");
            }
            res.push_back(res_str);
        }

        vec.pop_back();

        return;
    }

public:
    vector<string> binaryTreePaths(TreeNode *root)
    {
        dfs(root);
        return res;
    }
};

int main()
{
    TreeNode root(1), node_2(2), node_3(3), node_5(5);
    root.left = &node_2;
    root.right = &node_3;
    node_2.right = &node_5;

    Solution sol;
    vector<string> res;
    res = sol.binaryTreePaths(&root);

    for (auto e : res) {
        cout << e << "\n";
    }
}
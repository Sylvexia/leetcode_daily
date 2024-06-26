// 1382. Balance a Binary Search Tree

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
    vector<int> m_data;
    void get_data(TreeNode *root)
    {
        if (!root)
            return;
        get_data(root->left);
        m_data.push_back(root->val);
        get_data(root->right);
    }

    TreeNode *build_tree(int l, int r, TreeNode *root, vector<int> &data)
    {
        if (l > r)
            return nullptr;

        int m = (l + r) / 2;
        root = new TreeNode(data[m]);
        root->left = build_tree(l, m - 1, root->left, data);
        root->right = build_tree(m + 1, r, root->right, data);
        return root;
    }

public:
    TreeNode *balanceBST(TreeNode *root)
    {
        get_data(root);
        TreeNode *res = build_tree(0, m_data.size() - 1, root, m_data);
        return res;
    }
};

int main()
{
    TreeNode *node1 = new TreeNode(1);
    TreeNode *node2 = new TreeNode(2);
    TreeNode *node3 = new TreeNode(3);
    TreeNode *node4 = new TreeNode(4);
    node1->right = node2;
    node2->right = node3;
    node3->right = node4;

    Solution sol;
    TreeNode *res = sol.balanceBST(node1);
    cout << res->val;
}
// 872. Leaf-Similar Trees

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

class Solution
{
    void capture(TreeNode *root, vector<int> &vec)
    {
        if (!root)
            return;

        if (!root->left and !root->right) {
            vec.push_back(root->val);
            return;
        }

        capture(root->left, vec);
        capture(root->right, vec);

        return;
    }


public:
    bool leafSimilar(TreeNode *root1, TreeNode *root2)
    {
        vector<int> vec_1, vec_2;
        capture(root1, vec_1);
        capture(root2, vec_2);

        for (int i = 0; i < vec_1.size(); i++) {
            if (vec_1[i] != vec_2[i])
                return false;
        }

        return vec_1.size() == vec_2.size();
    }
};
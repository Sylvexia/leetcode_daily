// 654. Maximum Binary Tree

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

#include <bits/stdc++.h>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution {
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        if(nums.empty())
            return nullptr;
        auto max_it = max_element(nums.begin(), nums.end());
        vector<int> leftVec(nums.begin(), max_it);
        vector<int> rightVec(max_it+1, nums.end());
        TreeNode *root = new TreeNode(*max_it);
        root->left = constructMaximumBinaryTree(leftVec);
        root->right = constructMaximumBinaryTree(rightVec);
        return root;
    }
};
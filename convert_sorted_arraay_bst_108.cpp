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
public:
    TreeNode *append_recur(vector<int> &nums, int start, int end)
    {
        if (end <= start)
            return nullptr;

        int mid_idx = (start + end) / 2;

        TreeNode *root = new TreeNode(nums[mid_idx]);

        root->left = append_recur(nums, start, mid_idx);
        root->right = append_recur(nums, mid_idx+1, end);

        return root;
    }

    TreeNode *sortedArrayToBST(vector<int> &nums)
    {
        return append_recur(nums, 0, nums.size());
    }
};
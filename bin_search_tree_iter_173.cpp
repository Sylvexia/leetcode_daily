// 173. Binary Search Tree Iterator

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

int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class BSTIterator
{
    stack<TreeNode *> stk;

public:
    BSTIterator(TreeNode *root) { push_left(root); }

    int next()
    {
        TreeNode *top = stk.top();
        stk.pop();
        push_left(top->right);
        return top->val;
    }

    bool hasNext() { return !stk.empty(); }

    void push_left(TreeNode *node)
    {
        while (node) {
            stk.push(node);
            node = node->left;
        }
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */

class BSTIterator
{
    vector<int> vec;
    int idx = -1;
    void helper(TreeNode *node)
    {
        if (!node)
            return;
        helper(node->left);
        vec.push_back(node->val);
        helper(node->right);
    }

public:
    BSTIterator(TreeNode *root) { helper(root); }

    int next()
    {
        idx++;
        return vec[idx];
    }

    bool hasNext() { return idx < vec.size() - 1 or idx == -1; }
};
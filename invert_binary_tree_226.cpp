// 226. Invert Binary Tree

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
    void invert(TreeNode *root)
    {
        if (!root)
            return;

        invert(root->left);
        invert(root->right);

        TreeNode *temp;
        temp = root->left;
        root->left = root->right;
        root->right = temp;
    }

    TreeNode *invertTree(TreeNode *root)
    {
        invert(root);
        return root;
    }
};

class Solution
{
public:
    TreeNode *invertTree(TreeNode *root)
    {
        stack<TreeNode *> container;
        container.push(root);

        while (!container.empty())
        {
            TreeNode *todo = container.top();
            container.pop();

            if (!todo)
                continue;

            container.push(todo->left);
            container.push(todo->right);
            swap(todo->left, todo->right);
        }
        return root;
    }
};

class Solution
{
public:
    TreeNode *invertTree(TreeNode *root)
    {
        queue<TreeNode *> container;
        container.push(root);

        while (!container.empty())
        {
            TreeNode *todo = container.front();
            container.pop();

            if (!todo)
                continue;

            container.push(todo->left);
            container.push(todo->right);
            swap(todo->left, todo->right);
        }
        return root;
    }
};
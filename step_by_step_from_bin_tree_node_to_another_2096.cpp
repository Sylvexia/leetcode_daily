// 2096. Step-By-Step Directions From a Binary Tree Node to Another

#include <bits/stdc++.h>
#include <iterator>
#include <string>

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
    bool find(TreeNode *node, int val, string &path)
    {
        if (node->val == val)
            return true;

        if (node->left and find(node->left, val, path))
            path.push_back('L');
        else if (node->right and find(node->right, val, path))
            path.push_back('R');

        return !path.empty();
    }

public:
    string getDirections(TreeNode *root, int startValue, int destValue)
    {
        string start_path, dest_path;

        find(root, startValue, start_path);
        find(root, destValue, dest_path);

        while (!start_path.empty() and !dest_path.empty() and
               start_path.back() == dest_path.back()) {
            start_path.pop_back();
            dest_path.pop_back();
        }
        return string(start_path.size(), 'U') +
               string(dest_path.rbegin(), dest_path.rend());
    }
};
// 1028. Recover a Tree From Preorder Traversal

#include <bits/stdc++.h>
#include <cctype>
#include <cstddef>

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
    TreeNode *dfs(string &str, int depth, int &i)
    {
        if (i > str.size())
            return nullptr;

        int numDash = 0;
        while (i + numDash < str.size() and str[i + numDash] == '-')
            numDash++;

        if (numDash != depth)
            return nullptr;

        i += numDash;

        int val = 0;

        while (i < str.size() and isdigit(str[i])) {
            val = val * 10 + (str[i] - '0');
            i++;
        }

        TreeNode *node = new TreeNode(val);
        node->left = dfs(str, depth + 1, i);
        node->right = dfs(str, depth + 1, i);
        return node;
    }

public:
    TreeNode *recoverFromPreorder(string traversal)
    {
        int i = 0;
        return dfs(traversal, 0, i);
    }
};
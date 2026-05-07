// 894. All Possible Full Binary Trees

#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

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
    unordered_map<int, vector<TreeNode *>> memo;

public:
    vector<TreeNode *> allPossibleFBT(int n)
    {
        if (n % 2 == 0)
            return {};
        if (n == 1)
            return {new TreeNode()};
        if (memo.find(n) != memo.end())
            return memo[n];

        vector<TreeNode *> res;

        for (int i = 1; i < n; i += 2) {
            auto left = allPossibleFBT(i);
            auto right = allPossibleFBT(n - i - 1);

            for (auto l : left) {
                for (auto r : right) {
                    auto root = new TreeNode(0, l, r);
                    res.push_back(root);
                }
            }
        }
        return memo[n] = res;
    }
};
// 1367. Linked List in Binary Tree

#include <bits/stdc++.h>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

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
    vector<int> cache;
    bool check_res(vector<int> &cache, vector<int> &gen)
    {
        for (int i = 0; i < gen.size(); i++) {
            int j = 0;
            for (; j < cache.size() and i + j < gen.size(); j++) {
                if (gen[i + j] != cache[j])
                    break;
            }
            if (j == cache.size())
                return true;
        }
        return false;
    }
    bool dfs(TreeNode *root, vector<int> &gen)
    {
        if (!root)
            return false;
        gen.push_back(root->val);
        bool res = check_res(cache, gen);
        res |= dfs(root->left, gen);
        res |= dfs(root->right, gen);
        gen.pop_back();
        return res;
    }

public:
    bool isSubPath(ListNode *head, TreeNode *root)
    {
        for (ListNode *trav = head; trav; trav = trav->next)
            cache.push_back(trav->val);
        vector<int> gen;
        return dfs(root, gen);;
    }
};
// 109. Convert Sorted List to Binary Search Tree

#include <bits/stdc++.h>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

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
    TreeNode *build(ListNode *head, ListNode *tail)
    {
        if (!head)
            return nullptr;

        if (head == tail)
            return nullptr;

        ListNode *slow = head, *fast = head;
        while (fast != tail and fast->next != tail)
        {
            fast = fast->next->next;
            slow = slow->next;
        }

        TreeNode *ret = new TreeNode(slow->val);
        ret->left = build(head, slow);
        ret->right = build(slow->next, tail);

        return ret;
    }

public:
    TreeNode *sortedListToBST(ListNode *head)
    {
        return build(head, nullptr);
    }
};
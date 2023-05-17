// 2130. Maximum Twin Sum of a Linked List

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

class Solution
{
public:
    int pairSum(ListNode *head)
    {
        ListNode *slow = head;
        ListNode *fast = head;

        while (fast and fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode *cur = slow;
        ListNode *prev = nullptr;
        ListNode *next = slow;

        while (cur)
        {
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }

        int res = 0;
        while (prev)
        {
            res = max(res, head->val + prev->val);
            head = head->next;
            prev = prev->next;
        }

        return res;
    }
};
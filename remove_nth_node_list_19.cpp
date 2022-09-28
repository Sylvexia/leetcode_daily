// 19. Remove Nth Node From End of List

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
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode *iter = head;
        int len{};

        while (iter)
        {
            iter = iter->next;
            len++;
        }

        if (len == n)
            return head->next;

        iter = head;

        for (int i = 1; i < len - n; i++)
        {
            iter = iter->next;
        }

        iter->next = iter->next->next;

        return head;
    }
};
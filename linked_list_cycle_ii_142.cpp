// 142. Linked List Cycle II

#include <bits/stdc++.h>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    ListNode *detectCycle(ListNode *head)
    {

        ListNode *slow = head, *fast = head, *entry = head;

        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
            if (fast == slow)
                break;
        }
        if (!fast || !fast->next)
            return nullptr;
        while (entry != slow)
        {
            entry = entry->next;
            slow = slow->next;
        }
        return entry;
    }
};
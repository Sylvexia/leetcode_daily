// 24. Swap Nodes in Pairs

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
    ListNode *swapPairs(ListNode *head)
    {
        ListNode Dummy;
        Dummy.next = head;
        ListNode *t1 = &Dummy;
        ListNode *t2 = t1;

        while (t1->next and t1->next->next)
        {
            t2 = t1->next;
            t1->next = t1->next->next;
            t2->next = t2->next->next;
            t1->next->next = t2;
            t1 = t1->next->next;
        }
        return Dummy.next;
    }
};
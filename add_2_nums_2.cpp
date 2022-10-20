// 2. Add Two Numbers

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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        int carry = 0;
        ListNode *ret = new ListNode(0);
        ListNode *temp = ret;

        while (l1 && l2)
        {
            int sum = (l1->val + l2->val + carry);
            carry = sum / 10;
            temp->next = new ListNode(sum % 10);

            temp = temp->next;
            l1 = l1->next;
            l2 = l2->next;
        }

        while (l1)
        {
            int sum = (l1->val + carry);
            carry = sum / 10;
            temp->next = new ListNode(sum % 10);

            temp = temp->next;
            l1 = l1->next;
        }

        while (l2)
        {
            int sum = (l2->val + carry);
            carry = sum / 10;
            temp->next = new ListNode(sum % 10);

            temp = temp->next;
            l2 = l2->next;
        }

        if (carry)
            temp->next = new ListNode(carry);

        return ret->next;
    }
};
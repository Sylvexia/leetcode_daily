// 25. Reverse Nodes in k-Group

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
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        ListNode *prev = head;
        for (int i = 0; i < k; i++)
        {
            if (!prev)
                return head;
            prev = prev->next;
        }

        ListNode *cur = head;
        for (int i = 0; i < k; i++)
        {
            ListNode *next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        head->next = reverseKGroup(cur, k);
        return prev;
    }
};

class Solution
{
public:
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        ListNode dummy(0, head);

        ListNode *prev = &dummy;
        ListNode *curr = dummy.next;
        ListNode *temp = NULL;

        int count = k;

        while (curr != NULL)
        {
            if (count > 1)
            {
                temp = prev->next;
                prev->next = curr->next;
                curr->next = curr->next->next;
                prev->next->next = temp;

                count--;
            }
            else
            {
                prev = curr;
                curr = curr->next;
                count = k;

                ListNode *end = curr;
                for (int i = 0; i < k; i++)
                {
                    if (end == NULL)
                    {
                        return dummy.next;
                    }
                    end = end->next;
                }
            }
        }

        return dummy.next;
    }
};
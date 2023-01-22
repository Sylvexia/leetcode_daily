// 23. Merge k Sorted Lists

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
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        struct cmp
        {
            bool operator()(const ListNode *l1, const ListNode *l2)
            {
                return l1->val > l2->val;
            }
        };

        priority_queue<ListNode *, vector<ListNode *>, cmp> pq{};

        for (auto l : lists)
        {
            if (l)
                pq.push(l);
        }

        ListNode dummy(0);
        ListNode *node = &dummy;

        while (pq.size())
        {
            ListNode *top = pq.top();
            pq.pop();

            node->next = top;
            node=node->next;

            if (top->next)
                pq.push(top->next);
        }

        return dummy.next;
    }
};
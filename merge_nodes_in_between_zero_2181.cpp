// 2181. Merge Nodes in Between Zeros

#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
public:
    ListNode *mergeNodes(ListNode *head)
    {
        ListNode *cur = head;

        while (cur->next) {
            ListNode *trav = cur->next;
            for (; trav and trav->val != 0; trav = trav->next) {
                cur->val += trav->val;
            }
            if (!trav->next) {
                cur->next = nullptr;
                return head;
            }
            cur->next = trav;
            cur = trav;
        }

        return head;
    }
};
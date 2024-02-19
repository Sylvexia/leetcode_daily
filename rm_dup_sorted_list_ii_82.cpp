// 82. Remove Duplicates from Sorted List II

#include <bits/stdc++.h>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *deleteDuplicates(ListNode *head)
    {
        ListNode dummy;
        dummy.next = head;
        ListNode *cur = &dummy;
        while (cur and cur->next) {
            ListNode *next = cur->next, *trav = next->next;
            if (next and trav and next->val == trav->val) {
                while (trav and next->val == trav->val)
                    trav = trav->next;
                cur->next = trav;
            } else
                cur = cur->next;
        }

        return dummy.next;
    }
};
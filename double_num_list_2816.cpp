// 2816. Double a Number Represented as a Linked List

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
    ListNode *doubleIt(ListNode *head)
    {
        if (head->val > 4)
            head = new ListNode(0, head);

        for (ListNode *node = head; node; node = node->next) {
            node->val = (node->val << 1) % 10;
            if (node->next and node->next->val > 4)
                node->val++;
        }
        return head;
    }
};
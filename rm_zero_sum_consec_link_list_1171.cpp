// 1171. Remove Zero Sum Consecutive Nodes from Linked List

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
    ListNode *removeZeroSumSublists(ListNode *head)
    {
        ListNode dummy(0, head);
        int prefix = 0;
        unordered_map<int, ListNode *> seen;
        for (ListNode *i = &dummy; i; i = i->next) {
            prefix += i->val;
            seen[prefix] = i;
        }
        prefix = 0;
        for (ListNode *i = &dummy; i; i = i->next) {
            prefix += i->val;
            i->next = seen[prefix]->next;
        }
        return dummy.next;
    }
};
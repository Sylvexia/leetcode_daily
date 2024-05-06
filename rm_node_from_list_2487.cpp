// 2487. Remove Nodes From Linked List

#include <bits/stdc++.h>
#include <climits>

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
    ListNode *removeNodes(ListNode *head)
    {
        ListNode dummy(INT_MAX);
        vector<ListNode *> stack{&dummy};
        for (auto p = head; p; p = p->next) {
            while (stack.back()->val < p->val)
                stack.pop_back();
            stack.back()->next = p;
            stack.push_back(p);
        }
        return dummy.next;
    }
};
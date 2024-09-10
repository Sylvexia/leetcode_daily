// 2807. Insert Greatest Common Divisors in Linked List

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

class Solution {
public:
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* trav = head;

        while(trav->next)
        {
            int gcd_res = gcd(trav->val, trav->next->val);
            ListNode* new_node = new ListNode(gcd_res, trav->next);
            trav->next = new_node;
            trav = trav->next->next;
        }
        return head;
    }
};
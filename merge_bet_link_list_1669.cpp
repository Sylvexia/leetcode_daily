// 1669. Merge In Between Linked Lists

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
    ListNode *mergeInBetween(ListNode *list1, int a, int b, ListNode *list2)
    {
        ListNode dummy(0, list1);

        ListNode *trav = &dummy;
        for (int i = 0; i < a; i++) {
            trav = trav->next;
        }

        ListNode *sec1 = trav;

        for (int i = 0; i < b - a + 2; i++) {
            trav = trav->next;
        }

        ListNode *sec2 = trav;

        trav = list2;
        while (trav->next)
            trav = trav->next;

        sec1->next = list2;
        trav->next = sec2;

        return dummy.next;
    }
};
// 61. Rotate List

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
    ListNode *rotateRight(ListNode *head, int k)
    {
        if (!head)
            return nullptr;

        int size = 1;
        ListNode *tail = head;
        while (tail->next) {
            tail = tail->next;
            size++;
        }

        k = k % size;
        if (k == 0)
            return head;

        ListNode *trav = head;
        int step = size - k - 1;

        for (int i = 0; i < step; i++) {
            trav = trav->next;
        }

        ListNode *ret = trav->next;

        tail->next = head;
        trav->next = nullptr;
        return ret;
    }
};
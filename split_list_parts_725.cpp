// 725. Split Linked List in Parts

#include <bits/stdc++.h>

using namespace std;

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
    vector<ListNode *> splitListToParts(ListNode *head, int k)
    {
        int len = 0;
        ListNode *p = head;
        while (p) {
            len++;
            p = p->next;
        }

        int group = len / k;
        int remain = len % k;
        vector<ListNode *> res(k);

        p = head;

        ListNode *prev = nullptr;
        for (int i = 0; i < k; i++) {
            res[i] = p;
            for (int j = 0; j < group + (i + 1 <= remain); j++) {
                prev = p;
                p = p->next;
            }
            if (prev)
                prev->next = nullptr;
        }

        return res;
    }
};
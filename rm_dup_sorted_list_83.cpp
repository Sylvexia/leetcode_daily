// 83. Remove Duplicates from Sorted List

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
    ListNode *deleteDuplicates(ListNode *head)
    {
        ListNode *left = head;
        while (left) {
            ListNode *right = left->next;
            while (right and right->val == left->val)
                right = right->next;
            left->next = right;
            left = left->next;
        }
        return head;
    }
};
// 148. Sort List

#include <bits/stdc++.h>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *sortList(ListNode *head)
    {
        if (!head)
            return nullptr;
        vector<int> vec;
        ListNode *temp = head;
        while (temp)
        {
            vec.push_back(temp->val);
            temp = temp->next;
        }

        sort(vec.begin(), vec.end());
        ListNode *dummy = new ListNode();
        temp = dummy;

        for (int e : vec)
        {
            temp->next = new ListNode(e);
            temp = temp->next;
        }
        temp->next = nullptr;

        return dummy->next;
    }
};
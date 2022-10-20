// 143. Reorder List

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
    void reorderList(ListNode *head)
    {
        ListNode *trav = head;
        vector<ListNode *> vec;
        while (trav)
        {
            vec.push_back(trav);
            trav = trav->next;
        }

        int l = 1, r = vec.size() - 1;

        for (int i = 0; i < vec.size(); i++)
        {
            if (i & 1)
            {
                head->next = vec[l];
                l++;
            }
            else
            {
                head->next = vec[r];
                r--;
            }
            head = head->next;
        }
        head->next = nullptr;
    }
};
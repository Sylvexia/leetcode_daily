// 382. Linked List Random Node

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
    vector<int> m_val;

public:
    Solution(ListNode *head)
    {
        ListNode *temp = head;
        srand(time(0));
        while (temp)
        {
            m_val.push_back(temp->val);
            temp = temp->next;
        }
    }

    int getRandom()
    {
        return m_val[rand() % m_val.size()];
    }
};
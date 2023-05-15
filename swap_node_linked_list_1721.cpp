// 1721. Swapping Nodes in a Linked List

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
    ListNode *swapNodes(ListNode *head, int k)
    {
        vector<int> buf;
        ListNode *temp = head;
        while (temp)
        {
            buf.push_back(temp->val);
            temp = temp->next;
        }
        
        k--;
        swap(buf[k], buf[buf.size() - k - 1]);

        ListNode ret;
        temp = &ret;
        for (int e : buf)
        {
            temp->next = new ListNode(e);
            temp = temp->next;
        }
        return ret.next;
    }
};
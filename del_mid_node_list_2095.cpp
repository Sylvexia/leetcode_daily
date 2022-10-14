// 2095. Delete the Middle Node of a Linked List

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
    ListNode *deleteMiddle(ListNode *head)
    {
        if (!head->next)
            return nullptr;

        int size = 0;
        ListNode *trav = head;

        while (trav)
        {
            trav = trav->next;
            size++;
        }

        int del_idx = size / 2;
        int idx = 1;
        trav = head;

        while (idx != del_idx)
        {
            trav = trav->next;
            idx++;
        }

        trav->next = trav->next->next;
        return head;
    }
};
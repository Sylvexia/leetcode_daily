// 86. Partition List

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
    ListNode *partition(ListNode *head, int x)
    {
        ListNode right(0);
        ListNode left(0);

        ListNode *r = &right;
        ListNode *l = &left;

        while (head)
        {
            if (head->val < x)
            {
                l->next = head;
                l = l->next;
            }
            else
            {
                r->next = head;
                r = r->next;
            }
            head = head->next;
        }
        l->next = right.next;
        r->next = nullptr;
        return left.next;
    }
};
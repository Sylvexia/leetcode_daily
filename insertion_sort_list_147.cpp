// 147. Insertion Sort List

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
#include <iostream>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
public:
    ListNode *insertionSortList(ListNode *head)
    {
        ListNode dummy(0);
        ListNode* curr = head;

        while(curr)
        {
            ListNode *prev = &dummy;
            while(prev->next and prev->next->val <= curr->val)
                prev = prev->next;
            ListNode* next = curr->next;
            curr->next = prev->next;
            prev->next = curr;
            curr = next;
        }
        return dummy.next;
    }
};
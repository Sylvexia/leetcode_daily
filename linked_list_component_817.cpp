// 817. Linked List Components

#include <unordered_set>
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
    int numComponents(ListNode *head, vector<int> &nums)
    {
        unordered_set<int> u_set(nums.begin(), nums.end());
        int res = 0;
        while (head) {
            res += (u_set.count(head->val) and
                    ((!head->next) or !u_set.count(head->next->val)));
            head = head->next;
        }
        return res;
    }
};
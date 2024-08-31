// 3217. Delete Nodes From Linked List Present in Array

#include <bits/stdc++.h>
#include <unordered_set>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
public:
    ListNode *modifiedList(vector<int> &nums, ListNode *head)
    {
        unordered_set<int> u_set(nums.begin(), nums.end());
        ListNode dummy;
        ListNode *dummy_iter = &dummy;
        for (ListNode *trav = head; trav; trav = trav->next) {
            int val = trav->val;
            if (u_set.find(val) == u_set.end()) {
                dummy_iter->next = new ListNode(val);
                dummy_iter = dummy_iter->next;
            }
        }
        return dummy.next;
    }
};
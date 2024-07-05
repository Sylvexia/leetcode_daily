// 2058. Find the Minimum and Maximum Number of Nodes Between Critical Points

#include <bits/stdc++.h>
#include <climits>

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
    vector<int> nodesBetweenCriticalPoints(ListNode *head)
    {
        vector<int> critical;

        ListNode *prev = head;
        ListNode *cur = head->next;
        int position = 1;

        while (cur->next) {
            if (cur->val > prev->val and cur->val > cur->next->val)
                critical.push_back(position);
            else if (cur->val < prev->val and cur->val < cur->next->val)
                critical.push_back(position);

            cur = cur->next;
            prev = prev->next;
            position++;
        }

        if (critical.size() < 2)
            return {-1, -1};

        int res_min = INT_MAX;

        for (int i = 0; i < critical.size() - 1; i++) {
            res_min = min(res_min, critical[i + 1] - critical[i]);
        }

        int res_max = critical[critical.size() - 1] - critical[0];

        return {res_min, res_max};
    }
};
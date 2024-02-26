// 2462. Total Cost to Hire K Workers

#include <bits/stdc++.h>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
public:
    long long totalCost(vector<int> &costs, int k, int candidates)
    {
        long long res = 0;
        int n = costs.size();
        int l = 0, r = n - 1;
        priority_queue<int, vector<int>, greater<int>> left_q, right_q;
        while (k) {
            while (left_q.size() < candidates and l <= r)
                left_q.push(costs[l++]);
            while (right_q.size() < candidates and l <= r)
                right_q.push(costs[r--]);
            int lc = left_q.empty() ? INT_MAX : left_q.top();
            int rc = right_q.empty() ? INT_MAX : right_q.top();
            if (lc <= rc) {
                res += lc;
                left_q.pop();
            } else {
                res += rc;
                right_q.pop();
            }
            k--;
        }
        return res;
    }
};
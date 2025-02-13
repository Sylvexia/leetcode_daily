// 3066. Minimum Operations to Exceed Threshold Value II

#include <bits/stdc++.h>
#include <queue>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
public:
    int minOperations(vector<int> &nums, int k)
    {
        priority_queue<long long, vector<long long>, greater<long long>> pq(
            nums.begin(), nums.end());
        int res = 0;
        while (pq.top() < k) {
            long long top1 = pq.top();
            pq.pop();
            long long top2 = pq.top();
            pq.pop();
            pq.push(min(top1, top2) * 2 + max(top1, top2));
            res++;
        }
        return res;
    }
};
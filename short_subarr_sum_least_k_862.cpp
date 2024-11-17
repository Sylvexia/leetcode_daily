// 862. Shortest Subarray with Sum at Least K

#include <bits/stdc++.h>
#include <climits>
#include <queue>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
    typedef pair<long long, int> pli;

public:
    int shortestSubarray(vector<int> &nums, int k)
    {
        int n = nums.size();
        int res = INT_MAX;
        long long sum = 0;
        priority_queue<pli, vector<pli>, greater<>> pq;
        for (int i = 0; i < n; i++) {
            sum += nums[i];
            if (sum >= k)
                res = min(res, i + 1);
            while (!pq.empty() and sum - pq.top().first >= k) {
                res = min(res, i - pq.top().second);
                pq.pop();
            }
            pq.push({sum, i});
        }
        return res == INT_MAX ? -1 : res;
    }
};
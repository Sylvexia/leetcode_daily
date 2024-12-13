// 2593. Find Score of an Array After Marking All Elements

#include <bits/stdc++.h>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
    typedef pair<int, int> pii;

public:
    long long findScore(vector<int> &nums)
    {
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            pq.push({nums[i], i});
        }

        unordered_set<int> used;
        long long res = 0;
        while (used.size() < n) {
            auto [val, index] = pq.top();
            pq.pop();
            if (!used.count(index)) {
                res += val;
                used.insert(index);
                used.insert(max(index - 1, 0));
                used.insert(min(index + 1, n - 1));
            }
        }
        return res;
    }
};
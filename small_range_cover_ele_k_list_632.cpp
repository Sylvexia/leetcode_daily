// 632. Smallest Range Covering Elements from K Lists

#include <bits/stdc++.h>
#include <algorithm>
#include <climits>
#include <queue>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
public:
    vector<int> smallestRange(vector<vector<int>> &nums)
    {
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>,
                       greater<tuple<int, int, int>>>
            pq;

        int max_val = INT_MIN;
        for (int i = 0; i < nums.size(); i++) {
            pq.push({nums[i][0], i, 0});
            max_val = max(max_val, nums[i][0]);
        }

        int res_min = 0, res_max = INT_MAX;
        while (pq.size() == nums.size()) {
            auto [min_val, num_i, ele_i] = pq.top();
            pq.pop();
            if (max_val - min_val < res_max - res_min) {
                res_min = min_val;
                res_max = max_val;
            }
            if (ele_i + 1 < nums[num_i].size()) {
                int next_val = nums[num_i][ele_i + 1];
                pq.push({next_val, num_i, ele_i + 1});
                max_val = max(max_val, next_val);
            }
        }

        return {res_min, res_max};
    }
};
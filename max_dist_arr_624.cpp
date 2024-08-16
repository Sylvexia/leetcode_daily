// 624. Maximum Distance in Arrays

#include <bits/stdc++.h>
#include <algorithm>
#include <climits>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
public:
    int maxDistance(vector<vector<int>> &arrays)
    {
        vector<int> mins, maxs;
        for (auto &arr : arrays) {
            mins.push_back(arr[0]);
            maxs.push_back(arr[arr.size() - 1]);
        }

        int res = -1;
        int cur_min = maxs[0];
        int cur_max = mins[0];

        for (int i = 0; i < arrays.size(); i++) {
            res = max(res, max(maxs[i] - cur_min, cur_max - mins[i]));
            cur_min = min(cur_min, mins[i]);
            cur_max = max(cur_max, maxs[i]);
        }

        return res;
    }
};
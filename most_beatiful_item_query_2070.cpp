// 2070. Most Beautiful Item for Each Query

#include <bits/stdc++.h>
#include <climits>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
    int bin_search(vector<vector<int>> &items, int target)
    {
        int l = 0;
        int r = items.size() - 1;
        int res = 0;
        while (l <= r) {
            int m = l + (r - l) / 2;
            if (items[m][0] > target)
                r = m - 1;
            else {
                res = max(res, items[m][1]);
                l = m + 1;
            }
        }
        return res;
    }

public:
    vector<int> maximumBeauty(vector<vector<int>> &items, vector<int> &queries)
    {
        sort(items.begin(), items.end(),
             [](vector<int> &a, vector<int> &b) { return a[0] < b[0]; });
        int maxBeauty = INT_MIN;
        for (auto &i : items) {
            maxBeauty = max(maxBeauty, i[1]);
            i[1] = maxBeauty;
        }
        vector<int> res;
        for (int i = 0; i < queries.size(); i++)
            res.push_back(bin_search(items, queries[i]));
        return res;
    }
};
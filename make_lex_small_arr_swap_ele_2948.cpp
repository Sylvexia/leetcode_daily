// 2948. Make Lexicographically Smallest Array by Swapping Elements

#include <bits/stdc++.h>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
    using pii = pair<int, int>;

public:
    vector<int> lexicographicallySmallestArray(vector<int> &nums, int limit)
    {
        vector<pii> sorted;
        int n = nums.size();
        for (int i = 0; i < n; i++)
            sorted.push_back({nums[i], i});
        sort(sorted.begin(), sorted.end());

        vector<vector<pii>> groups{{sorted[0]}};
        for (int i = 1; i < n; i++) {
            if (sorted[i].first - sorted[i - 1].first <= limit)
                groups.back().push_back(sorted[i]);
            else
                groups.push_back({sorted[i]});
        }

        for (auto &g : groups) {
            vector<int> indices;
            for (auto [val, idx] : g)
                indices.push_back(idx);
            sort(indices.begin(), indices.end());

            for (int i = 0; i < indices.size(); i++)
                nums[indices[i]] = g[i].first;
        }
        return nums;
    }
};
// 2453. Destroy Sequential Targets

#include <algorithm>
#include <iostream>
#include <unordered_map>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
public:
    int destroyTargets(vector<int> &nums, int space)
    {
        using pii = pair<int, int>;

        // mod -> <count, minKey>
        unordered_map<int, pii> u_map;
        for (int n : nums) {
            int mod = n % space;

            if (!u_map.count(mod)) {
                u_map[mod] = {1, n};
            } else {
                u_map[mod].first++;
                u_map[mod].second = min(u_map[mod].second, n);
            }
        }

        int bestCount = 0;
        int res = INT_MAX;

        for(auto &[mod, data]: u_map)
        {
            auto [count, minKey] = data;

            if(count > bestCount)
            {
                bestCount = count;
                res = minKey;
            }
            else if (count == bestCount)
                res = min(res, minKey);
        }

        return res;
    }
};
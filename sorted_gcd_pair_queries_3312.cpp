// 3312. Sorted GCD Pair Queries

#include <algorithm>
#include <iostream>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
public:
    vector<int> gcdValues(vector<int> &nums, vector<long long> &queries)
    {
        int mx = *ranges::max_element(nums);

        vector<int> freq(mx + 1, 0);
        for (int x : nums)
            freq[x]++;

        vector<long long> gcdCount(mx + 1, 0);
        for (int g = mx; g >= 1; g--) {
            long long div = 0;
            for (int m = g; m <= mx; m += g)
                div += freq[m];

            gcdCount[g] = div * (div - 1) / 2;
            for (int m = 2 * g; m <= mx; m += g)
                gcdCount[g] -= gcdCount[m];
        }

        vector<long long> prefix(mx + 1, 0);

        for (int g = 1; g <= mx; g++)
            prefix[g] = prefix[g - 1] + gcdCount[g];

        vector<int> res;
        res.reserve(queries.size());

        for (long long query : queries) {
            int gcdValue = upper_bound(prefix.begin(), prefix.end(), query) -
                           prefix.begin();

            res.push_back(gcdValue);
        }
        return res;
    }
};
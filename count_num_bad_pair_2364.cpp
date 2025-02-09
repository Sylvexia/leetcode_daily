// 2364. Count Number of Bad Pairs

#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
    inline long long c2(long long a) { return a * (a - 1) / 2; }

public:
    long long countBadPairs(vector<int> &nums)
    {
        int n = nums.size();
        unordered_map<int, int> offset_count;
        for (int i = 0; i < n; i++)
            offset_count[nums[i] - i]++;

        long long res = c2(n);
        for (auto [key, count] : offset_count) {
            if (count > 1)
                res -= c2(count);
        }
        return res;
    }
};
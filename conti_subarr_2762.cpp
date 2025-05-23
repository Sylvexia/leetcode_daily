// 2762. Continuous Subarrays

#include <bits/stdc++.h>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
public:
    long long continuousSubarrays(vector<int> &nums)
    {
        int n = nums.size();
        long long res = 0;
        map<int, int> map;
        for (int l = 0, r = 0; r < n; r++) {
            map[nums[r]]++;
            while (l < r and prev(map.end())->first - map.begin()->first > 2) {
                int f = --map[nums[l]];
                if (f == 0)
                    map.erase(nums[l]);
                l++;
            }
            res += r - l + 1LL;
        }
        return res;
    }
};
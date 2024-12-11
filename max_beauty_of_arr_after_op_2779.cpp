// 2779. Maximum Beauty of an Array After Applying Operation

#include <bits/stdc++.h>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
public:
    int maximumBeauty(vector<int> &nums, int k)
    {
        map<int, int> map;
        for (int n : nums) {
            map[n - k]++;
            map[n + k + 1]--;
        }

        int curSum = 0;
        int res = 1;
        for (auto [key, val] : map) {
            curSum += val;
            res = max(res, curSum);
        }

        return res;
    }
};
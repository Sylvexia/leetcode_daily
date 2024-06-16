// 330. Patching Array

#include <bits/stdc++.h>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
public:
    int minPatches(vector<int> &nums, int n)
    {
        int i = 0;
        int res = 0;
        long long max_num = 0;
        while (max_num < n) {
            if (i < nums.size() and nums[i] <= max_num + 1) {
                max_num += nums[i];
                i++;
            } else {
                max_num += max_num + 1;
                res++;
            }
        }
        return res;
    }
};
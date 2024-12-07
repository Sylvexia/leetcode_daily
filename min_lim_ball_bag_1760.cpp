#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
    bool cond(int m, vector<int> &nums, int maxOperations)
    {
        int totalOps = 0;
        for (int n : nums) {
            int curOps = ceil(n / (double) m) - 1;
            totalOps += curOps;
            if (totalOps > maxOperations)
                return false;
        }
        return true;
    }

public:
    int minimumSize(vector<int> &nums, int maxOperations)
    {
        int l = 1;
        int r = *max_element(nums.begin(), nums.end());

        while (l < r) {
            int m = l + (r - l) / 2;
            if (cond(m, nums, maxOperations))
                r = m;
            else
                l = m + 1;
        }
        return l;
    }
};
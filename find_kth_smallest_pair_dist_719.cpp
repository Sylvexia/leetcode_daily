// 719. Find K-th Smallest Pair Distance

#include <bits/stdc++.h>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
    bool enough(int m, vector<int> &nums, int k)
    {
        int n = nums.size();
        int count = 0;
        int i = 0, j = 0;

        while (i < n or j < n) {
            while (j < n and nums[j] - nums[i] <= m)
                j++;
            count += (j - i - 1);
            i++;
        }
        return count >= k;
    }

public:
    int smallestDistancePair(vector<int> &nums, int k)
    {
        sort(nums.begin(), nums.end());

        int n = nums.size();
        int l = 0, r = nums[n - 1] - nums[0];

        while (l < r) {
            int m = l + (r - l) / 2;
            if (enough(m, nums, k))
                r = m;
            else
                l = m + 1;
        }
        return l;
    }
};
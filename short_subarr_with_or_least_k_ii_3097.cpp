// 3097. Shortest Subarray With OR at Least K II

#include <bits/stdc++.h>
#include <climits>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
    void update(array<int, 32> &freq, int num, int delta)
    {
        for (int i = 0; i < 32; i++) {
            if ((num >> i) & 1)
                freq[i] += delta;
        }
    }

    int freqToNumber(array<int, 32> &freq)
    {
        int res = 0;
        for (int i = 0; i < 32; i++) {
            if (freq[i] != 0)
                res |= 1 << i;
        }
        return res;
    }

public:
    int minimumSubarrayLength(vector<int> &nums, int k)
    {
        if (k == 0)
            return 1;
        int n = nums.size();
        int res = INT_MAX;
        int l = 0;
        array<int, 32> freq;
        for (int i = 0; i < 32; i++)
            freq[i] = 0;

        for (int r = 0; r < n; r++) {
            update(freq, nums[r], 1);
            while (l <= r and freqToNumber(freq) >= k) {
                res = min(res, r - l + 1);
                update(freq, nums[l], -1);
                l++;
            }
        }
        if (res == INT_MAX)
            return -1;
        return res;
    }
};
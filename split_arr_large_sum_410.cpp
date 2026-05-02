// 410. Split Array Largest Sum

#include <bits/stdc++.h>
#include <numeric>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
    bool cond(int m, int k, vector<int> &nums)
    {
        int sum = 0;
        int count = 1;
        for (int n : nums) {
            if (sum + n > m) {
                count++;
                sum = n;
            } else {
                sum += n;
            }
        }
        return count <= k;
    }

public:
    int splitArray(vector<int> &nums, int k)
    {
        int l = *max_element(nums.begin(), nums.end());
        int r = accumulate(nums.begin(), nums.end(), (int) 0);

        while (l < r) {
            int m = l + (r - l) / 2;
            if (cond(m, k, nums))
                r = m;
            else
                l = m + 1;
        }

        return l;
    }
};
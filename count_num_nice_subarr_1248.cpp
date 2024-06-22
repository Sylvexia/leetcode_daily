// 1248. Count Number of Nice Subarrays

#include <bits/stdc++.h>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
    int atMost(vector<int> &nums, int k)
    {
        int res = 0, i = 0;
        for (int j = 0; j < nums.size(); j++) {
            k -= nums[j] % 2;
            while (k < 0)
                k += nums[i++] % 2;
            res += j - i + 1;
        }
        return res;
    }

public:
    int numberOfSubarrays(vector<int> &nums, int k)
    {
        return atMost(nums, k) - atMost(nums, k - 1);
    }
};
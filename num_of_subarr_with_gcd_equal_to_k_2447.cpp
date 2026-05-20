// 2447. Number of Subarrays With GCD Equal to K

#include <bits/stdc++.h>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
public:
    int subarrayGCD(vector<int> &nums, int k)
    {
        int n = nums.size();
        int res = 0;

        for (int i = 0; i < n; i++) {
            int cur = 0;
            for (int j = i; j < n; j++) {
                cur = gcd(cur, nums[j]);
                res += cur == k;
            }
        }
        return res;
    }
};
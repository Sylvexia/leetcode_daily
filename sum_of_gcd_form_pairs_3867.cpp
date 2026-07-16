// 2615. Sum of Distances

#include <iostream>
#include <numeric>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
public:
    long long gcdSum(vector<int> &nums)
    {
        int mx = INT_MIN, n = nums.size();
        vector<int> prefixGcd(n);
        for (int i = 0; i < n; i++) {
            mx = max(mx, nums[i]);
            prefixGcd[i] = gcd(nums[i], mx);
        }
        ranges::sort(prefixGcd);
        long long res = 0;
        for (int i = 0; i < n / 2; i++) {
            res += gcd(prefixGcd[i], prefixGcd[n - 1 - i]);
        }
        return res;
    }
};
// 1979. Find Greatest Common Divisor of Array

#include <climits>
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
    int findGCD(vector<int> &nums)
    {
        int mx = INT_MIN;
        int mn = INT_MAX;
        for (int n : nums) {
            mx = max(mx, n);
            mn = min(mn, n);
        }
        return gcd(mx, mn);
    }
};
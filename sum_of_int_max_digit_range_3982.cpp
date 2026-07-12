// 3982. Sum of Integers with Maximum Digit Range

#include <iostream>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
    int getRange(int x)
    {
        int mn = 9, mx = 0;
        while (x > 0) {
            int d = x % 10;
            mn = min(mn, d);
            mx = max(mx, d);
            x /= 10;
        }

        return mx - mn;
    }

public:
    int maxDigitRange(vector<int> &nums) {
        int maxRange = -1;
        long long ans = 0;

        for (int x : nums) {
            int r = getRange(x);

            if (r > maxRange) {
                maxRange = r;
                ans = x;
            } else if (r == maxRange) {
                ans += x;
            }
        }

        return ans;
    }
};
// 485. Max Consecutive Ones

#include <bits/stdc++.h>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
public:
    int findMaxConsecutiveOnes(vector<int> &nums)
    {
        int res = 0;
        int count = 0;

        for (int n : nums) {
            if (n == 0)
                count = 0;
            else
                count += 1;

            res = max(res, count);
        }
        return res;
    }
};
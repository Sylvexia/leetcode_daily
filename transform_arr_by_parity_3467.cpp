// 3467. Transform Array by Parity

#include <bits/stdc++.h>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();


class Solution
{
public:
    vector<int> transformArray(vector<int> &nums)
    {
        for (auto &n : nums)
            if (n % 2 == 0)
                n = 0;
            else
                n = 1;
        sort(nums.begin(),nums.end());
        return nums;
    }
};
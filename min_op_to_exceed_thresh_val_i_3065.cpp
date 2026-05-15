// 3065. Minimum Operations to Exceed Threshold Value I

#include <bits/stdc++.h>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
public:
    int minOperations(vector<int> &nums, int k)
    {
        int res = 0;
        for (int n : nums)
            res += n < k;
        return res;
    }
};
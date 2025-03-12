// 2529. Maximum Count of Positive Integer and Negative Integer

#include <bits/stdc++.h>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
public:
    int maximumCount(vector<int> &nums)
    {
        int pos = 0;
        int neg = 0;

        for (int i = 0; i < nums.size(); i++) {
            pos += nums[i] > 0;
            neg += nums[i] < 0;
        }
        return max(pos, neg);
    }
};
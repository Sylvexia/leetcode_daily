// 2270. Number of Ways to Split Array

#include <bits/stdc++.h>
#include <numeric>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
public:
    int waysToSplitArray(vector<int> &nums)
    {
        long long int sum =
            accumulate(nums.begin(), nums.end(), (long long int) 0);

        long long int curSum = 0;
        int res = 0;
        for (int i = 0; i < nums.size() - 1; i++) {
            curSum += nums[i];
            res += (curSum >= sum - curSum);
        }
        return res;
    }
};
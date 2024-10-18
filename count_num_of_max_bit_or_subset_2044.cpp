// 2044. Count Number of Maximum Bitwise-OR Subsets

#include <bits/stdc++.h>
#include <algorithm>
#include <unordered_map>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
    int dfs(int i, int cur, int maxVal, vector<int> &nums)
    {
        if (i >= nums.size())
            return (cur == maxVal) ? 1 : 0;

        int not_take = dfs(i + 1, cur, maxVal, nums);
        int take = dfs(i + 1, cur | nums[i], maxVal, nums);
        return take + not_take;
    }

public:
    int countMaxOrSubsets(vector<int> &nums)
    {
        int maxVal = 0;
        for (int n : nums)
            maxVal |= n;
        return dfs(0, 0, maxVal, nums);
    }
};
// 1799. Maximize Score After N Operations

#include <bits/stdc++.h>

using namespace std;

// fuck i can't do this one

class Solution
{
    int n;
    unordered_map<int, map<vector<int>, int>> dp;

    int dfs(int ind, vector<int> &vis, vector<int> &nums)
    {
        if (ind == n / 2)
            return 0;

        if (dp.find(ind) != dp.end() and
            dp[ind].find(vis) != dp[ind].end())
            return dp[ind][vis];

        int ma = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (vis[i] == 0 and vis[j] == 0)
                {
                    vis[i] = 1;
                    vis[j] = 1;
                    ma = max(ma, (ind + 1) * __gcd(nums[j], nums[i]) + dfs(ind + 1, vis, nums));
                    vis[i] = 0;
                    vis[j] = 0;
                }
            }
        }
        return dp[ind][vis] = ma;
    }

public:
    int maxScore(vector<int> &nums)
    {
        n = nums.size();
        vector<int> vis(n + 1, 0);
        return dfs(0, vis, nums);
    }
}; // this get tle

class Solution
{
public:
    int dp[1 << 14];
    int gcd(int a, int b)
    {
        if (b == 0)
            return a;
        return gcd(b, a % b);
    }
    int dfs(vector<int> &nums, int state, int current)
    {
        if (current == 0)
            return 0;
        if (dp[state])
            return dp[state];
        int result = 0, n = nums.size();

        vector<int> total;

        // index of nums elements that are not used yet
        for (int i = 0; i < n; i++)
            if (state & (1 << i))
                total.push_back(i);

        // mark total[i] and total[j] as used with bit compression technique
        for (int i = 0; i < total.size(); i++)
            for (int j = i + 1; j < total.size(); j++)
                result = max(result,
                             gcd(nums[total[i]], nums[total[j]]) *
                                     current +
                                 dfs(nums,
                                     (state & (~((1 << total[i]) | (1 << total[j])))),
                                     current - 1));

        dp[state] = result;
        return result;
    }
    int maxScore(vector<int> &nums)
    {
        memset(dp, 0, sizeof(dp));
        return dfs(nums, (1 << 14) - 1, nums.size() / 2);
    }
};
// 689. Maximum Sum of 3 Non-Overlapping Subarrays

#include <bits/stdc++.h>
#include <climits>

using namespace std;

class Solution
{
    int getOptimal(vector<int> &sums,
                   int k,
                   int idx,
                   int rem,
                   vector<vector<int>> &memo)
    {
        if (rem == 0)
            return 0;
        if (idx >= sums.size())
            return rem > 0 ? INT_MIN : 0;
        if (memo[idx][rem] != -1)
            return memo[idx][rem];
        int take = sums[idx] + getOptimal(sums, k, idx + k, rem - 1, memo);
        int not_take = getOptimal(sums, k, idx + 1, rem, memo);
        memo[idx][rem] = max(take, not_take);
        return memo[idx][rem];
    }
    void dfs(vector<int> &sums,
             int k,
             int idx,
             int rem,
             vector<vector<int>> &memo,
             vector<int> &indices)
    {
        if (rem == 0)
            return;
        if (idx >= sums.size())
            return;

        int take = sums[idx] + getOptimal(sums, k, idx + k, rem - 1, memo);
        int not_take = getOptimal(sums, k, idx + 1, rem, memo);
        if (take >= not_take) {
            indices.push_back(idx);
            dfs(sums, k, idx + k, rem - 1, memo, indices);
        } else {
            dfs(sums, k, idx + 1, rem, memo, indices);
        }
    }

public:
    vector<int> maxSumOfThreeSubarrays(vector<int> &nums, int k)
    {
        int n = nums.size() - k + 1;

        vector<int> sums(n);
        for (int i = 0; i < n; i++) {
            int local = 0;
            for (int j = 0; j < k; j++)
                local += nums[i + j];
            sums[i] = local;
        }

        vector<vector<int>> cache(n, vector<int>(4, -1));
        getOptimal(sums, k, 0, 3, cache);
        vector<int> rem;
        dfs(sums, k, 0, 3, cache, rem);
        return rem;
    }
};
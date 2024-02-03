// 1043. Partition Array for Maximum Sum

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int maxSumAfterPartitioning(vector<int> &arr, int k)
    {
        vector<int> dp(arr.size());

        for (int i = 0; i < arr.size(); i++) {
            int cur_max = 0;
            for (int j = 1; j <= k and i - j + 1 >= 0; ++j) {
                cur_max = max(cur_max, arr[i - j + 1]);
                dp[i] = max(dp[i], (i >= j ? dp[i - j] : 0) + cur_max * j);
            }
        }
        return dp[arr.size() - 1];
    }
};
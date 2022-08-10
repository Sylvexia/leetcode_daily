// 823. Binary Trees With Factors
#include <bits/stdc++.h>

using namespace std;
class Solution
{
public:
    int numFactoredBinaryTrees(vector<int> &arr)
    {
        long res = 0;
        const int mod = 1e9 + 7;
        unordered_map<int, long> dp;

        sort(arr.begin(), arr.end());

        for (int i = 0; i < arr.size(); i++)
        {
            dp[arr[i]] = 1;

            for (int j = 0; j < i; ++j)
            {
                if (arr[i] % arr[j] == 0)
                {
                    dp[arr[i]] = (dp[arr[i]] + dp[arr[j]] * dp[arr[i] / arr[j]]) % mod;
                }
            }

            res = (res + dp[arr[i]]) % mod;
        }

        return res;
    }
};
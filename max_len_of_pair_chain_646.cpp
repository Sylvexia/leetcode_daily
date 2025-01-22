// 646. Maximum Length of Pair Chain

#include <bits/stdc++.h>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
public:
    int findLongestChain(vector<vector<int>> &pairs)
    {
        auto comp = [&](vector<int> &a, vector<int> &b) { return a[0] < b[0]; };
        sort(pairs.begin(), pairs.end(), comp);

        int n = pairs.size();
        vector<int> dp(n);
        for (int i = 0; i < n; i++) {
            dp[i] = 1;
            for (int j = 0; j < i; j++) {
                if (pairs[j][1] < pairs[i][0])
                    dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        return dp[n - 1];
    }
};
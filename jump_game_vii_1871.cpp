// 1871. Jump Game VII

#include <bits/stdc++.h>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
public:
    bool canReach(string s, int minJump, int maxJump)
    {
        int n = s.size();
        vector<bool> dp(n, false);
        dp[0] = true;

        int numAproach = 0;

        for (int i = 1; i < n; i++) {
            if (i >= minJump and dp[i - minJump])
                numAproach++;
            if (i > maxJump and dp[i - maxJump - 1])
                numAproach--;
            dp[i] = numAproach > 0 and s[i] == '0';
        }

        return dp[n - 1];
    }
};
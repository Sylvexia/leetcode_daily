// 1894. Find the Student that Will Replace the Chalk

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
    int chalkReplacer(vector<int> &chalk, int k)
    {
        int n = chalk.size();
        vector<long long int> prefix(n, 0);
        prefix[0] = chalk[0];
        for (int i = 0; i < n - 1; i++)
            prefix[i + 1] = prefix[i] + chalk[i + 1];

        long long int remain = k % prefix[n - 1];
        for (int i = 0; i < n; i++) {
            if (remain < prefix[i])
                return i;
        }
        return n - 1;
    }
};
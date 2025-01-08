// 3042. Count Prefix and Suffix Pairs I

#include <bits/stdc++.h>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
public:
    int countPrefixSuffixPairs(vector<string> &words)
    {
        int n = words.size();
        int res = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int m = words[i].size();
                int p = words[j].size();
                if (m > p)
                    continue;
                bool cur = true;
                for (int k = 0; k < m; k++) {
                    if (words[i][k] != words[j][k] ||
                        words[i][m - k - 1] != words[j][p - k - 1]) {
                        cur = false;
                        break;
                    }
                }
                res += cur;
            }
        }
        return res;
    }
};
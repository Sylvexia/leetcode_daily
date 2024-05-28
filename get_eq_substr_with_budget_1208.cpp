// 1208. Get Equal Substrings Within Budget

#include <bits/stdc++.h>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
public:
    int equalSubstring(string s, string t, int maxCost)
    {
        int n = s.size();
        vector<int> dist(n);

        for (int i = 0; i < n; i++)
            dist[i] = abs(s[i] - t[i]);

        int l = 0, r = 0, sum = 0;
        int res = 0;
        for (; l < n; l++) {
            for (; r < n; r++) {
                sum += dist[r];
                if (sum > maxCost) {
                    r++;
                    break;
                }
                res = max(res, r - l + 1);
            }
            sum -= dist[l];
        }
        return res;
    }
};
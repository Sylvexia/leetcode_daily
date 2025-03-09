// 3208. Alternating Groups II

#include <bits/stdc++.h>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
public:
    int numberOfAlternatingGroups(vector<int> &colors, int k)
    {
        for (int i = 0; i < k - 1; i++)
            colors.push_back(colors[i]);

        int n = colors.size();
        int res = 0;
        for (int i = 0; i < n; i++) {
            int j = i + 1;
            for (; j < n and colors[j] != colors[j - 1]; j++) {
            }
            res += max(0, j - i - k + 1);
            i = j - 1;
        }

        return res;
    }
};
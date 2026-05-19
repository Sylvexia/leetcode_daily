// 2865. Beautiful Towers I

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
    long long maximumSumOfHeights(vector<int> &heights)
    {
        int n = heights.size();
        long long res = 0;
        for (int i = 0; i < n; i++) {
            vector<int> temp = heights;
            for (int j = i - 1; j >= 0; j--) {
                if (temp[j] <= temp[j + 1])
                    continue;
                temp[j] = temp[j + 1];
            }
            for (int j = i + 1; j < n; j++) {
                if (temp[j] <= temp[j - 1])
                    continue;
                temp[j] = temp[j - 1];
            }
            res = max(res, accumulate(begin(temp), end(temp), (long long) 0));
        }

        return res;
    }
};
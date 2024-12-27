// 1014. Best Sightseeing Pair

#include <bits/stdc++.h>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
public:
    int maxScoreSightseeingPair(vector<int> &values)
    {
        int n = values.size();
        vector<int> maxLeftScore(n);
        maxLeftScore[0] = values[0];

        int res = 0;
        for (int i = 1; i < n; i++) {
            int curR = values[i] - i;
            res = max(res, maxLeftScore[i - 1] + curR);
            int curL = values[i] + i;
            maxLeftScore[i] = max(maxLeftScore[i - 1], curL);
        }
        return res;
    }
};
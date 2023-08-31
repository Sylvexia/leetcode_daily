// 1326. Minimum Number of Taps to Open to Water a Garden

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int minTaps(int n, vector<int> &ranges)
    {
        int can_reach[n + 1];
        memset(can_reach, 0, sizeof(can_reach));

        // vector<int> can_reach(n + 1, 0);

        for (int i = 0; i < ranges.size(); i++) {
            int left = max(0, i - ranges[i]);
            int right = min(n, i + ranges[i]);
            can_reach[left] = max(can_reach[left], right);
        }

        int res = 0;
        int cur_max = 0;
        int next_max = 0;

        for (int i = 0; i <= n; i++) {
            if (i > next_max)
                return -1;
            if (i > cur_max) {
                res++;
                cur_max = next_max;
            }
            next_max = max(next_max, can_reach[i]);
        }

        return res;
    }
};
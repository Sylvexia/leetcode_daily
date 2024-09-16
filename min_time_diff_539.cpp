// 539. Minimum Time Difference

#include <bits/stdc++.h>
#include <climits>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
    inline int get_num(char tens, char ones)
    {
        return (tens - '0') * 10 + (ones - '0');
    }
    inline int get_min(string &str)
    {
        return get_num(str[0], str[1]) * 60 + get_num(str[3], str[4]);
    }
    inline int get_diff(string low, string high)
    {
        int low_min = get_min(low);
        int high_min = get_min(high);
        return high_min - low_min;
    }

public:
    int findMinDifference(vector<string> &timePoints)
    {
        int n = timePoints.size();
        sort(timePoints.begin(), timePoints.end());
        int res = INT_MAX;
        for (int i = 1; i < n; i++) {
            res = min(res, get_diff(timePoints[i - 1], timePoints[i]));
        }
        return min(res, get_min(timePoints[0]) + 1440 - get_min(timePoints[n-1]));
    }
};
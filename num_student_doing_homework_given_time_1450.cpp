// 1450. Number of Students Doing Homework at a Given Time

#include <bits/stdc++.h>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
public:
    int busyStudent(vector<int> &startTime, vector<int> &endTime, int queryTime)
    {
        int n = startTime.size();
        int res = 0;
        for (int i = 0; i < n; i++) {
            res += ((queryTime >= startTime[i]) and (queryTime <= endTime[i]));
        }
        return res;
    }
};
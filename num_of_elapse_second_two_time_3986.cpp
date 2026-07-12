// 3986. Number of Elapsed Seconds Between Two Times

#include <iostream>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
    int getTime(string &str)
    {
        int h = (str[0] - '0') * 10 + str[1] - '0';
        int m = (str[3] - '0') * 10 + str[4] - '0';
        int s = (str[6] - '0') * 10 + str[7] - '0';
        return h * 3600 + m * 60 + s;
    }

public:
    int secondsBetweenTimes(string startTime, string endTime)
    {
        return getTime(endTime) - getTime(startTime);
    }
};
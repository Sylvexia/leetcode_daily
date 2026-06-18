// 1344. Angle Between Hands of a Clock

#include <iostream>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
public:
    double angleClock(int hour, int minutes)
    {
        double m = minutes * 6;
        double h = (hour % 12) * 30 + 0.5 * minutes;
        double diff = abs(h - m);

        return min(diff, 360 - diff);
    }
};
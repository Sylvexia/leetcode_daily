// 1870. Minimum Speed to Arrive on Time

#include <bits/stdc++.h>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
public:
    int minSpeedOnTime(vector<int> &dist, double hour)
    {
        auto feasible = [&](int speed) {
            double time = 0;
            int n = dist.size();
            for (int i = 0; i < n - 1; i++) {
                time += ceil((double) dist[i] / speed);
            }
            time += (double) dist[n - 1] / speed;
            return time <= hour;
        };

        int yes = 1e7 + 1;
        int no = 0;

        while (abs(yes - no) > 1) {
            long long m = (yes + no) / 2;
            if (feasible(m))
                yes = m;
            else
                no = m;
        }
        return yes == 1e7 + 1 ? -1 : yes;
    }
};
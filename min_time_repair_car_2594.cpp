// 2594. Minimum Time to Repair Cars

#include <bits/stdc++.h>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
public:
    long long repairCars(vector<int> &ranks, int cars)
    {
        auto cond = [&](long long m) {
            long long canRepair = 0;
            for (int r : ranks)
                canRepair += (int) sqrt(m / r);
            return canRepair >= cars;
        };

        long long yes = 1e16;
        long long no = 0;

        while (abs(yes - no) > 1) {
            long long m = (yes + no) / 2;
            if (cond(m))
                yes = m;
            else
                no = m;
        }
        return yes;
    }
};
// 2960. Count Tested Devices After Test Operations

#include <bits/stdc++.h>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
public:
    int countTestedDevices(vector<int> &batteryPercentages)
    {
        int n = batteryPercentages.size();
        int res = 0;
        for (int i = 0; i < n; i++) {
            if (batteryPercentages[i] > 0) {
                res++;
                for (int j = i + 1; j < n; j++) {
                    batteryPercentages[j] = max(0, batteryPercentages[j] - 1);
                }
            }
        }
        return res;
    }
};
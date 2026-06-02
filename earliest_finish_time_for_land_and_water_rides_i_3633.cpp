// 3633. Earliest Finish Time for Land and Water Rides I

#include <bits/stdc++.h>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution {
    int cal(vector<int>& startA, vector<int>& durA, vector<int>& startB, vector<int>& durB) {
        int minVal = INT_MAX;

        for (int i = 0; i < startA.size(); i++)
            minVal = min(minVal, startA[i] + durA[i]);

        int res = INT_MAX;

        for (int i = 0; i < startB.size(); i++)
            res = min(res, max(minVal, startB[i]) + durB[i]);

        return res;
    }
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        return min(cal(landStartTime, landDuration, waterStartTime, waterDuration),
            cal(waterStartTime, waterDuration, landStartTime, landDuration));
    }
};
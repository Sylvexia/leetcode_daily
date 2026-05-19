// 3531. Count Covered Buildings

#include <bits/stdc++.h>
#include <climits>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
public:
    int countCoveredBuildings(int n, vector<vector<int>> &buildings)
    {
        vector<int> iMax(n + 1, INT_MIN), iMin(n + 1, INT_MAX),
            jMax(n + 1, INT_MIN), jMin(n + 1, INT_MAX);

        for (auto &b : buildings) {
            int iVal = b[0];
            int jVal = b[1];
            iMax[jVal] = max(iMax[jVal], iVal);
            jMax[iVal] = max(jMax[iVal], jVal);
            iMin[jVal] = min(iMin[jVal], iVal);
            jMin[iVal] = min(jMin[iVal], jVal);
        }

        int res = 0;
        for (auto &b : buildings) {
            int iVal = b[0];
            int jVal = b[1];
            if (iVal < iMax[jVal] and iVal > iMin[jVal] and
                jVal < jMax[iVal] and jVal > jMin[iVal])
                res++;
        }
        return res;
    }
};
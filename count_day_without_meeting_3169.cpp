// 3169. Count Days Without Meetings

#include <bits/stdc++.h>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
public:
    int countDays(int days, vector<vector<int>> &meetings)
    {
        map<int, int> map;
        int prevDay = days;
        for (auto &m : meetings) {
            prevDay = min(prevDay, m[0]);
            map[m[0]]++;
            map[m[1] + 1]--;
        }

        int freeDay = prevDay - 1;
        int intersect = 0;
        for (auto [curDay, line] : map) {
            if (intersect == 0)
                freeDay += curDay - prevDay;
            intersect += line;
            prevDay = curDay;
        }
        freeDay += days - prevDay + 1;
        return freeDay;
    }
};
// 3160. Find the Number of Distinct Colors Among the Balls

#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
public:
    vector<int> queryResults(int limit, vector<vector<int>> &queries)
    {
        unordered_map<int, int> getCount, getColor;
        vector<int> res;
        for (auto &q : queries) {
            int index = q[0];
            int color = q[1];

            if (getColor[index] == 0) {
                getColor[index] = color;

                getCount[color]++;
            } else if (getColor[index] != color) {
                int origColor = getColor[index];
                getColor[index] = color;
                getCount[origColor]--;
                if (getCount[origColor] == 0)
                    getCount.erase(origColor);

                getCount[color]++;
            }
            res.push_back(getCount.size());
        }
        return res;
    }
};
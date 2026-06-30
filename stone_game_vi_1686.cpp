// 1686. Stone Game VI

#include <algorithm>
#include <iostream>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
public:
    int stoneGameVI(vector<int> &aliceValues, vector<int> &bobValues)
    {
        vector<array<int, 3>> vec;
        int n = aliceValues.size();
        for (int i = 0; i < n; i++)
            vec.push_back(
                {aliceValues[i] + bobValues[i], aliceValues[i], bobValues[i]});

        ranges::sort(vec);

        int a = 0, b = 0;
        for (int i = 0; i < n; i++) {
            a += i % 2 ? 0 : vec[n - i - 1][1];
            b += i % 2 ? vec[n - i - 1][2] : 0;
        }
        return a == b ? 0 : a > b ? 1 : -1;
    }
};
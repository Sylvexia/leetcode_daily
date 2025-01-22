// 123. Best Time to Buy and Sell Stock III

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
    int maxProfit(vector<int> &prices)
    {
        vector<int> buys(3, INT_MIN), sells(3, 0);

        for (auto p : prices) {
            for (int k = 1; k <= 2; k++) {
                buys[k] = max(sells[k - 1] - p, buys[k]);
                sells[k] = max(buys[k] + p, sells[k]);
            }
        }
        return sells[2];
    }
};
// 2144. Minimum Cost of Buying Candies With Discount

#include <bits/stdc++.h>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution {
public:
    int minimumCost(vector<int>& cost) {
        ranges::sort(cost, greater<int>());
        int n = cost.size();

        int res = 0;
        for (int i = 0; i < n; i++)
        {
            if ((i + 1) % 3)
                res += cost[i];
        }

        return res;
    }
};
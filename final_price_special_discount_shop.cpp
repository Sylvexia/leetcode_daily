// 1475. Final Prices With a Special Discount in a Shop

#include <bits/stdc++.h>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
public:
    vector<int> finalPrices(vector<int> &prices)
    {
        stack<int> stk;
        stk.push(0);
        for (int i = 1; i < prices.size(); i++) {
            while (stk.size() and prices[i] <= prices[stk.top()]) {
                prices[stk.top()] -= prices[i];
                stk.pop();
            }
            stk.push(i);
        }
        return prices;
    }
};
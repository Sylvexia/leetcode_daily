// 122. Best Time to Buy and Sell Stock II

#include <bits/stdc++.h>

using namespace std;

int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int prev = prices[0];
        int res = 0;
        for (int num : prices) {
            if (num > prev)
                res += num - prev;
            prev = num;
        }
        return res;
    }
};
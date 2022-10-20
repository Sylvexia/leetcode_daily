// 121. Best Time to Buy and Sell Stock

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int left = 0, right = 1, max_profit = 0;
        while (right < prices.size())
        {
            if (prices[left] < prices[right])
                max_profit = max(max_profit, prices[right] - prices[left]);
            else
                left = right;

            right++;
        }
        return max_profit;
    }
};
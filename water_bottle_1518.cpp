// 1518. Water Bottles

#include <bits/stdc++.h>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
public:
    int numWaterBottles(int numBottles, int numExchange)
    {
        int res = numBottles;
        int div = numBottles / numExchange;
        int mod = numBottles % numExchange;
        while (div != 0) {
            int pre_div = div;
            int pre_mod = mod;
            res += div;
            mod = (pre_div + pre_mod) % numExchange;
            div = (pre_div + pre_mod) / numExchange;
        }
        return res;
    }
};
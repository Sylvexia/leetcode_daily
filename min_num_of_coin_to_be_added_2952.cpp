// 2952. Minimum Number of Coins to be Added

#include <bits/stdc++.h>
#include <queue>

using namespace std;

class Solution
{
public:
    int minimumAddedCoins(vector<int> &coins, int target)
    {
        sort(coins.begin(), coins.end());

        int maxApproach = 0;
        int i = 0;
        int res = 0;
        while (maxApproach < target) {
            if (i < coins.size() and maxApproach + 1 >= coins[i]) {
                maxApproach += coins[i];
                i++;
            } else {
                maxApproach += maxApproach + 1;
                res++;
            }
        }
        return res;
    }
};
// 1359. Count All Valid Pickup and Delivery Options

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int countOrders(int n)
    {
        long long int res = 1;
        long long int mod = 1e9 + 7;
        int counter = 1;

        for (int i = 0; i < n; i++) {
            res *= counter;
            counter++;

            res *= counter;
            counter++;

            res /= 2;
            res %= mod;
        }

        return res;
    }
};
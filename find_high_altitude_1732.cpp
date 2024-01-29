// 1732. Find the Highest Altitude

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int largestAltitude(vector<int> &gain)
    {
        int res = 0;
        int sum = 0;
        for (int n : gain) {
            sum += n;
            res = max(res, sum);
        }
        return res;
    }
};
// 2145. Count the Hidden Sequences

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int numberOfArrays(vector<int> &differences, int lower, int upper)
    {
        long long maxNum = 0, minNum = 0, cur = 0;
        for (int d : differences) {
            cur += d;
            maxNum = max(maxNum, cur);
            minNum = min(minNum, cur);
        }
        long long res = (upper - lower) - (maxNum - minNum) + 1;
        return res < 0 ? 0 : res;
    }
};
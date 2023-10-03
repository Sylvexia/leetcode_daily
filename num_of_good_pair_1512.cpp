// 1512. Number of Good Pairs

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int numIdenticalPairs(vector<int> &nums)
    {
        unordered_map<int, int> cnt;

        for (int n : nums)
            cnt[n]++;

        int res = 0;
        for (auto [k, v] : cnt)
            res += (v * (v - 1) / 2);

        return res;
    }
};
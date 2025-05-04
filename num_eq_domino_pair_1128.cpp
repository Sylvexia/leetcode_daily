// 1128. Number of Equivalent Domino Pairs

#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    int numEquivDominoPairs(vector<vector<int>> &dominoes)
    {
        unordered_map<int, int> uMap;
        for (auto &d : dominoes) {
            if (d[0] > d[1])
                uMap[d[1] * 10 + d[0]]++;
            else
                uMap[d[0] * 10 + d[1]]++;
        }

        int res = 0;
        for (auto [key, val] : uMap)
            res += val * (val - 1) / 2;

        return res;
    }
};
// 781. Rabbits in Forest

#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    int numRabbits(vector<int> &answers)
    {
        unordered_map<int, int> uMap;
        for (int a : answers)
            uMap[a]++;
        int res = 0;
        for (auto [key, val] : uMap)
            res += (val + key) / (key + 1) * (key + 1);
        return res;
    }
};
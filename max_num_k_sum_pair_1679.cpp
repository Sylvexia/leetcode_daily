// 1679. Max Number of K-Sum Pairs

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int maxOperations(vector<int> &nums, int k)
    {
        unordered_map<int, int> u_map;
        for (int num : nums)
            u_map[num]++;

        int res = 0;
        for (auto [key, val] : u_map) {
            if (!u_map.count(k - key))
                continue;

            if (key == k - key) {
                res += val / 2;
                continue;
            }

            int min_val = min(u_map[key], u_map[k - key]);
            res += min_val;
            u_map[key] -= min_val;
            u_map[k - key] -= min_val;
        }

        return res;
    }
};
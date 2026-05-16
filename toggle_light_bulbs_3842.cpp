// 3842. Toggle Light Bulbs

#include <bits/stdc++.h>
#include <algorithm>
#include <unordered_map>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
public:
    vector<int> toggleLightBulbs(vector<int> &bulbs)
    {
        unordered_map<int, int> u_map;
        for (int b : bulbs)
            u_map[b]++;
        vector<int> res;
        for (auto [key, val] : u_map) {
            if (val % 2)
                res.push_back(key);
        }
        ranges::sort(res);
        return res;
    }
};
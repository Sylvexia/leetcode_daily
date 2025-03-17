// 2206. Divide Array Into Equal Pairs

#include <bits/stdc++.h>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
public:
    bool divideArray(vector<int> &nums)
    {
        unordered_map<int, int> u_map;

        for (int n : nums) {
            u_map[n]++;
        }

        bool res = true;
        for (auto [key, val] : u_map)
            if (val % 2 == 1)
                res = false;
        return res;
    }
};
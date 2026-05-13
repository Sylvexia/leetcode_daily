// 1394. Find Lucky Integer in an Array

#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();


class Solution
{
public:
    int findLucky(vector<int> &arr)
    {
        unordered_map<int, int> u_map;
        for (int n : arr)
            u_map[n]++;

        int res = -1;
        for (auto [key, val] : u_map) {
            if (key == val)
                res = max(res, val);
        }
        return res;
    }
};
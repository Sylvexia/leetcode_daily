// 1049. Last Stone Weight II

#include <bits/stdc++.h>
#include <climits>
#include <unordered_set>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
public:
    int lastStoneWeightII(vector<int> &stones)
    {
        unordered_set<int> u_set{0};
        for (auto s : stones) {
            unordered_set<int> cache;
            for (auto val : u_set)
                cache.insert({val + s, val - s});
            swap(u_set, cache);
        }

        int res = INT_MAX;
        for (int val : u_set)
            res = min(abs(val), res);
        return res;
    }
};
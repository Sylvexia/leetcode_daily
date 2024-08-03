// 1460. Make Two Arrays Equal by Reversing Subarrays

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
    bool canBeEqual(vector<int> &target, vector<int> &arr)
    {
        unordered_map<int, int> u_map1, u_map2;
        for (int n : target)
            u_map1[n]++;
        for (int n : arr)
            u_map2[n]++;

        if (u_map1.size() != u_map2.size())
            return false;

        for (auto [key, value] : u_map1)
            if (u_map1[key] != u_map2[key])
                return false;

        return true;
    }
};
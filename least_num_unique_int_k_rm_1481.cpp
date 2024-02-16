// 1481. Least Number of Unique Integers after K Removals

#include <bits/stdc++.h>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
public:
    int findLeastNumOfUniqueInts(vector<int> &arr, int k)
    {
        unordered_map<int, int> u_map;
        for (int n : arr)
            u_map[n]++;
        int res = u_map.size();
        vector<int> vec;
        for (auto [key, count] : u_map)
            vec.push_back(count);

        sort(vec.begin(), vec.end(), greater<int>());

        while (k > 0) {
            k -= vec.back();
            vec.pop_back();
            res -= (k >= 0);
        }
        return res;
    }
};
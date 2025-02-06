// 1726. Tuple with Same Product

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
    int tupleSameProduct(vector<int> &nums)
    {
        int n = nums.size();
        unordered_map<int, int> u_map;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++)
                u_map[nums[i] * nums[j]]++;
        }

        int res = 0;
        for (auto [key, count] : u_map)
            res += (count * (count - 1)) * 4;
        return res;
    }
};
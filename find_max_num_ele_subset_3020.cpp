// 3020. Find the Maximum Number of Elements in Subset

#include <iostream>
#include <unordered_map>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
public:
    int maximumLength(vector<int> &nums)
    {
        unordered_map<long long, int> u_map;
        for (int n : nums)
            u_map[n]++;

        int res = 1;
        if (u_map.count(1)) {
            int cnt = u_map[1];
            res = max(res, cnt % 2 ? cnt : cnt - 1);
            u_map.erase(1);
        }

        for (auto [key, val] : u_map) {
            long long cur = key;
            int len = 0;
            while (u_map.count(cur) and u_map[cur] >= 2) {
                len += 2;
                if (cur > 1e9)
                    break;
                cur *= cur;
            }
            if (u_map.count(cur))
                len++;
            else
                len--;
            res = max(res, len);
        }

        return res;
    }
};
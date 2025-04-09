// 3375. Minimum Operations to Make Array Values Equal to K

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
    int minOperations(vector<int> &nums, int k)
    {
        unordered_map<int, int> u_map;

        for (auto n : nums) {
            if (n < k)
                return -1;
            else if (n > k)
                u_map[n]++;
        }
        return u_map.size();
    }
};
// 930. Binary Subarrays With Sum

#include <bits/stdc++.h>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
public:
    int numSubarraysWithSum(vector<int> &nums, int goal)
    {
        unordered_map<int, int> count{{0, 1}};
        int prefix_sum = 0, res = 0;
        for (int n : nums) {
            prefix_sum += n;
            res += count[prefix_sum - goal];
            count[prefix_sum]++;
        }
        return res;
    }
};
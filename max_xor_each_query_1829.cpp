// 1829. Maximum XOR for Each Query

#include <bits/stdc++.h>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
public:
    vector<int> getMaximumXor(vector<int> &nums, int maximumBit)
    {
        int n = nums.size();
        vector<int> res(n);

        int xors = 0;
        int max_num = (1 << maximumBit) - 1;
        for (int i = 0; i < n; i++) {
            xors ^= nums[i];
            res[n - i - 1] = xors ^ max_num;
        }
        return res;
    }
};
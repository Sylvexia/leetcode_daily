// 995. Minimum Number of K Consecutive Bit Flips

#include <bits/stdc++.h>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
public:
    int minKBitFlips(vector<int> &nums, int k)
    {
        int flipped = 0, res = 0;
        vector<int> isflipped(nums.size());

        for (int i = 0; i < nums.size(); i++) {
            if (i >= k)
                flipped ^= isflipped[i - k];
            if (flipped == nums[i]) {
                if (i + k > nums.size())
                    return -1;
                isflipped[i] = 1;
                flipped ^= 1;
                res++;
            }
        }
        return res;
    }
};
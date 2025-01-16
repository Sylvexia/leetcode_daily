// 2425. Bitwise XOR of All Pairings

#include <bits/stdc++.h>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
public:
    int xorAllNums(vector<int> &nums1, vector<int> &nums2)
    {
        int res = 0;
        if (nums2.size() & 1) {
            for (auto n : nums1)
                res ^= n;
        }
        if (nums1.size() & 1) {
            for (auto n : nums2)
                res ^= n;
        }
        return res;
    }
};
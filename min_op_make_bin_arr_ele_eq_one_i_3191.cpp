// 3191. Minimum Operations to Make Binary Array Elements Equal to One I

#include <bits/stdc++.h>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
public:
    int minOperations(vector<int> &nums)
    {
        int n = nums.size();
        int res = 0;
        for (int i = 0; i < n - 2; i++) {
            if (nums[i] == 0) {
                nums[i] ^= 1;
                nums[i + 1] ^= 1;
                nums[i + 2] ^= 1;
                res++;
            }
        }
        bool pass = nums[n - 1] == 1 and nums[n - 2] == 1;
        return pass ? res : -1;
    }
};
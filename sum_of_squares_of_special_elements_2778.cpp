// 2778. Sum of Squares of Special Elements

#include <bits/stdc++.h>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
public:
    int sumOfSquares(vector<int> &nums)
    {
        int n = nums.size();
        int res = 0;
        for (int i = 0; i < n; i++) {
            int one_index = i + 1;
            if (n % one_index == 0)
                res += nums[i] * nums[i];
        }
        return res;
    }
};
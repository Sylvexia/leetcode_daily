// 3190. Find Minimum Operations to Make All Elements Divisible by Three

#include <bits/stdc++.h>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
public:
    int minimumOperations(vector<int> &nums)
    {
        int res = 0;
        for (int n : nums) {
            res += (n % 3 != 0);
        }
        return res;
    }
};
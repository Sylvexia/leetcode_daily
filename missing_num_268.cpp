// 268. Missing Number

#include <bits/stdc++.h>

using namespace std;

int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
public:
    int missingNumber(vector<int> &nums)
    {
        int res = nums.size();
        for (int i = 0; i < nums.size(); i++) {
            res ^= nums[i];
            res ^= i;
        }
        return res;
    }
};
// 3512. Minimum Operations to Make Array Sum Divisible by K

#include <bits/stdc++.h>
#include <numeric>

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
        return accumulate(nums.begin(), nums.end(), (int) 0) % k;
    }
};
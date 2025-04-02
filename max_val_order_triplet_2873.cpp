// 2873. Maximum Value of an Ordered Triplet I

#include <bits/stdc++.h>
#include <climits>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
public:
    long long maximumTripletValue(vector<int> &nums)
    {
        int n = nums.size();
        long long res = INT_MIN;
        for (int i = 0; i < n - 2; i++) {
            for (int j = i + 1; j < n - 1; j++) {
                for (int k = j + 1; k < n; k++)
                    res = max(res, ((long long) nums[i] - nums[j]) * nums[k]);
            }
        }
        return res < 0 ? 0 : res;
    }
};
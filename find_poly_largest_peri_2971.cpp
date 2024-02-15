// 2971. Find Polygon With the Largest Perimeter

#include <bits/stdc++.h>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
public:
    long long largestPerimeter(vector<int> &nums)
    {
        long long sum = 0, res = -1;
        int side = 0;
        sort(nums.begin(), nums.end());
        for (int n : nums) {
            side++;
            if (side >= 3 and sum > n)
                res = sum + n;
            sum += n;
        }
        return res;
    }
};
// 2134. Minimum Swaps to Group All 1's Together II

#include <bits/stdc++.h>
#include <climits>
#include <numeric>
#include <vector>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
public:
    int minSwaps(vector<int> &nums)
    {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        vector<int> v(nums.begin(), nums.end());
        v.insert(v.end(), nums.begin(), nums.end());

        int res = INT_MAX;
        int zeros = 0;

        for (int l = 0, r = 0; l < v.size(); l++) {
            while (r - l + 1 <= sum) {
                zeros += (v[r] == 0);
                r++;
                if (r >= v.size())
                    return res;
            }
            res = min(zeros, res);
            zeros -= (v[l] == 0);
        }
        return res;
    }
};
// 775. Global and Local Inversions

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
    bool isIdealPermutation(vector<int> &nums)
    {
        int cmax = INT_MIN, n = nums.size();
        for (int i = 0; i < n - 2; i++) {
            cmax = max(cmax, nums[i]);
            if (cmax > nums[i + 2])
                return false;
        }
        return true;
    }
};
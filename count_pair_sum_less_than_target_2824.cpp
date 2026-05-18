// 2824. Count Pairs Whose Sum is Less than Target

#include <bits/stdc++.h>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
public:
    int countPairs(vector<int> &nums, int target)
    {
        int n = nums.size();
        int res = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                res += (nums[i] + nums[j] < target);
            }
        }
        return res;
    }
};
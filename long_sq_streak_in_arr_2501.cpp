// 2501. Longest Square Streak in an Array

#include <bits/stdc++.h>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
public:
    int longestSquareStreak(vector<int> &nums)
    {
        int res = -1;
        unordered_set<int> u_set(nums.begin(), nums.end());
        for (int n : nums) {
            long long int cur = (long long int) n * n;
            int count = 1;
            while (cur < INT_MAX and u_set.count(cur)) {
                count++;
                res = max(res, count);
                cur = cur * cur;
            }
        }
        return res;
    }
};
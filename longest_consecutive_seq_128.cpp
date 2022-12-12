// 128. Longest Consecutive Sequence

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        unordered_set<int> u_set(nums.begin(), nums.end());
        int res = 0;
        for (auto &ele : u_set)
        {
            if (u_set.count(ele - 1))
                continue;

            int cur = 0;
            while (u_set.count(ele + cur))
                cur++;

            res = max(res, cur);
        }
        return res;
    }
};
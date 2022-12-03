// 198. House Robber

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int rob(vector<int> &nums)
    {
        int prev_1 = 0, prev_2 = 0, cur = 0;
        for (int ele : nums)
        {
            cur = max(prev_1, ele + prev_2);
            prev_2 = prev_1;
            prev_1 = cur;
        }
        return cur;
    }
};
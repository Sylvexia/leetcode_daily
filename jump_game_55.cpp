// 55. Jump Game

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    bool canJump(vector<int> &nums)
    {
        int cur_max = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            if (cur_max < i)
                return false;
            cur_max = max(cur_max, i + nums[i]);
        }

        return true;
    }
};
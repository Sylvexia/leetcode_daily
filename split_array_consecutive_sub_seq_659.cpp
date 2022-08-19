// 659. Split Array into Consecutive Subsequences

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    bool isPossible(vector<int> &nums)
    {
        unordered_map<int, int> left, end;

        for (auto num : nums)
            left[num]++;

        for (auto num : nums)
        {
            if (left[num] == 0)
                continue;

            left[num]--;

            if (end[num - 1] > 0)
            {
                end[num - 1]--;
                end[num]++;
            }
            else if (left[num + 1] > 0 && left[num + 2] > 0)
            {
                left[num + 1]--;
                left[num + 2]--;
                end[num + 2]++;
            }
            else
                return false;
        }

        return true;
    }
};
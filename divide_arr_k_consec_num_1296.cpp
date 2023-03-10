// 1296. Divide Array in Sets of K Consecutive Numbers

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    bool isPossibleDivide(vector<int> &nums, int k)
    {
        map<int, int> map_count;

        for (int ele : nums)
            map_count[ele]++;

        for (auto [key, val] : map_count)
        {
            if (map_count[key] > 0)
            {
                for (int i = 1; i < k; i++)
                {
                    if ((map_count[key + i] -= val) < 0)    // this will create shit
                        return false;
                }
            }
        }

        return true;
    }
};
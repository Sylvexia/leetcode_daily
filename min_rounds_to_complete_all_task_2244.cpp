// 2244. Minimum Rounds to Complete All Tasks

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int minimumRounds(vector<int> &tasks)
    {
        unordered_map<int, int> u_map{};
        int res{};
        for (auto ele : tasks)
            u_map[ele]++;

        //  1: 2,3, 2: 4,5,6
        for (auto [key, count] : u_map)
        {
            if (count < 2)
                return -1;

            res += (count + 2) / 3;
        }

        return res;
    }
};
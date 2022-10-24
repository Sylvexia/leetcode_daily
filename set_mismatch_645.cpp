// 645. Set Mismatch

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<int> findErrorNums(vector<int> &nums)
    {
        int array[nums.size()];
        vector<int> ret(2);

        for (int i = 0; i < nums.size(); i++)
            array[i] = 0;

        for (int i = 0; i < nums.size(); i++)
            array[nums[i] - 1]++;

        for (int i = 0; i < nums.size(); i++)
        {
            if (array[i] == 0)
                ret[1] = i + 1;

            if (array[i] == 2)
                ret[0] = i + 1;
        }

        return ret;
    }
};
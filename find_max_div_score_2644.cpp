// 2644. Find the Maximum Divisibility Score

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int maxDivScore(vector<int> &nums, vector<int> &divisors)
    {
        int score = INT_MIN, ret = INT_MAX;
        for (int i = 0; i < divisors.size(); i++)
        {
            int count = 0;
            for (int j = 0; j < nums.size(); j++)
            {
                if (nums[j] % divisors[i] == 0)
                    count++;
            }
            if (count > score or ((count == score) and divisors[i] < ret))
            {
                score = count;
                ret = divisors[i];
            }
        }

        if (score == INT_MIN)
            return *min_element(divisors.begin(), divisors.end());

        return ret;
    }
};
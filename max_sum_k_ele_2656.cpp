// 2656. Maximum Sum With Exactly K Elements

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int maximizeSum(vector<int> &nums, int k)
    {
        int score = 0;
        for (int i = 0; i < k; i++)
        {
            auto it = max_element(nums.begin(), nums.end());
            score += *it;
            *it = (*it) + 1;
        }

        return score;
    }
};

class Solution
{
public:
    int maximizeSum(vector<int> &nums, int k)
    {
        int m = *max_element(nums.begin(), nums.end());
        return (2 * m + k - 1) * (k) / 2;
    }
};
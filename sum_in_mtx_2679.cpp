// 2679. Sum in a Matrix

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int matrixSum(vector<vector<int>> &nums)
    {
        int score = 0;
        for (int i = 0; i < nums[0].size(); i++)
        {
            priority_queue<int> pq;
            for (auto &r : nums)
            {
                nth_element(r.begin(), r.begin() + i, r.end());
                pq.push(r[i]);
            }
            score += pq.top();
        }

        return score;
    }
};
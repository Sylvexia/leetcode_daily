// 1675. Minimize Deviation in Array

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int minimumDeviation(vector<int> &nums)
    {
        int min_val = INT_MAX;
        priority_queue<int> pq;

        for (auto n : nums)
        {
            if (n % 2 == 1)
                n *= 2;
            pq.push(n);
            min_val = min(min_val, n);
        }

        int min_dev = INT_MAX;

        while (true)
        {
            int max_val = pq.top();
            pq.pop();

            min_dev = min(min_dev, max_val - min_val);

            if (max_val % 2 == 1)
                break;

            max_val /= 2;
            min_val = min(min_val, max_val);
            pq.push(max_val);
        }

        return min_dev;
    }
};
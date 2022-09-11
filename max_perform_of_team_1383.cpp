// 1383. Maximum Performance of a Team

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int maxPerformance(int n, vector<int> &speed, vector<int> &efficiency, int k)
    {
        long sum{}, res{};
        priority_queue<int, vector<int>, greater<int>> pq;
        vector<pair<int, int>> attrs(n);

        for (int i = 0; i < n; ++i)
            attrs[i] = {efficiency[i], speed[i]};

        sort(rbegin(attrs), rend(attrs));

        for (auto &attr : attrs)
        {
            pq.emplace(attr.second);
            sum += attr.second;

            if (pq.size() > k)
            {
                sum -= pq.top();
                pq.pop();
            }
            res = max(res, sum * attr.first);
        }

        return res % (int)(1e9 + 7);
    }
};
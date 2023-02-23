// 502. IPO

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int findMaximizedCapital(int k, int w, vector<int> &profits, vector<int> &capital)
    {
        vector<pair<int, int>> data;
        for (int i = 0; i < profits.size(); ++i)
            data.push_back({profits[i], capital[i]});

        sort(data.begin(), data.end(), [](pair<int, int> &a, pair<int, int> &b)
             { return a.second < b.second; });

        priority_queue<int> pq; // max profit would be pop first, buffering the item can push, then take out the top most only
        int i = 0;
        while (k--)
        {
            while (i < profits.size() && w >= data[i].second)
                pq.push(data[i++].first);

            if (!pq.empty())
                w += pq.top(), pq.pop();
        }

        return w;
    }
};
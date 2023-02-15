// 1046. Last Stone Weight

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int lastStoneWeight(vector<int> &stones)
    {
        priority_queue<int> pq(stones.begin(), stones.end());

        while (pq.size() > 1)
        {
            int first = pq.top();
            pq.pop();

            int second = pq.top();
            pq.pop();

            int remain = first - second;
            if (remain)
                pq.push(remain);
        }

        return (pq.size() == 0) ? 0 : pq.top();
    }
};
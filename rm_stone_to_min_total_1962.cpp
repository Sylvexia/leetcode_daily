// 1962. Remove Stones to Minimize the Total

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int minStoneSum(vector<int> &piles, int k)
    {
        priority_queue<int> pq(piles.begin(), piles.end());

        for (int i = 0; i < k; i++)
        {
            int tp = pq.top();
            pq.pop();
            tp -= (tp >> 1);
            pq.push(tp);
        }

        int res{};
        while (!pq.empty())
        {
            res += pq.top();
            pq.pop();
        }
        return res;
    }
};
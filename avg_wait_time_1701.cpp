// 1701. Average Waiting Time

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    double averageWaitingTime(vector<vector<int>> &customers)
    {
        double total = 0;
        int cur = 0;

        for (auto &c : customers) {
            int arrive = c[0];
            int time = c[1];
            cur = max(cur, arrive) + time;
            total += cur - arrive;
        }
        return total / customers.size();
    }
};
// 621. Task Scheduler

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int leastInterval(vector<char> &tasks, int n)
    {
        array<int, 26> task_count;
        for (auto &ele : task_count)
            ele = 0;
        for (const auto &t : tasks)
            task_count[t - 'A']++;

        int res = 0;
        priority_queue<int> pq;

        for (const auto &cnt : task_count)
        {
            if (cnt != 0)
                pq.push(cnt);
        }

        int cycle = n + 1;

        while (!pq.empty())
        {
            vector<int> temp;
            int buffered = 0;
            for (int i = 0; i < cycle; ++i)
            {
                if (!pq.empty())
                {
                    temp.push_back(pq.top());
                    pq.pop();
                    buffered++;
                }
            }
            for (auto cnt : temp)
            {
                cnt--;
                if (cnt)
                    pq.push(cnt);
            }
            res += pq.empty() ? buffered : cycle;
        }

        return res;
    }
};
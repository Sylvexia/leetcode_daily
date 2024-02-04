// 933. Number of Recent Calls

#include <bits/stdc++.h>

using namespace std;

class RecentCounter
{
    queue<int> m_queue;

public:
    RecentCounter() { ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0); }

    int ping(int t)
    {
        m_queue.push(t);
        while (t - m_queue.front() > 3000)
            m_queue.pop();

        return m_queue.size();
    }
};
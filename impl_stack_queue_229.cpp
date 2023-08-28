// 225. Implement Stack using Queues

#include <bits/stdc++.h>

using namespace std;

class MyStack
{
    queue<int> m_q;

public:
    MyStack() {}

    void push(int x)
    {
        m_q.push(x);
        for (int i = 0; i < m_q.size() - 1; i++) {
            m_q.push(m_q.front());
            m_q.pop();
        }
    }

    int pop()
    {
        int val = m_q.front();
        m_q.pop();
        return val;
    }

    int top() { return m_q.front(); }

    bool empty() { return m_q.empty(); }
};

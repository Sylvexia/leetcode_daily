// 155. Min Stack

#include <bits/stdc++.h>

using namespace std;

class MinStack
{
private:
    vector<pair<int, int>> m_data{};

public:
    MinStack()
    {
    }

    void push(int val)
    {
        if (m_data.empty())
            m_data.push_back({val, val});
        else
            m_data.push_back({val, min(m_data.back().second, val)});
    }

    void pop()
    {
        m_data.pop_back();
    }

    int top()
    {
        return m_data.back().first;
    }

    int getMin()
    {
        return m_data.back().second;
    }
};
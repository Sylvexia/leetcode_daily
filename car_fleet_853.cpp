// 853. Car Fleet

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int carFleet(int target, vector<int> &position, vector<int> &speed)
    {
        vector<pair<int, int>> data;
        for (int i = 0; i < position.size(); i++)
            data.push_back({position[i], speed[i]});

        sort(data.begin(), data.end(), [](const auto &a, const auto &b)
             { return a.first < b.first; });

        stack<float> time_stack;

        for (auto &[m_pos, m_speed] : data)
        {
            float car_time = (target - m_pos) / (float)m_speed;
            while (!time_stack.empty() and car_time >= time_stack.top())
                time_stack.pop();
            time_stack.push(car_time);
        }

        return time_stack.size();
    }
};
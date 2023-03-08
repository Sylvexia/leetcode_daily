// 981. Time Based Key-Value Store

#include <bits/stdc++.h>

using namespace std;

class TimeMap
{
    unordered_map<string, map<int, string>> m_data;

public:
    TimeMap()
    {
    }

    void set(string key, string value, int timestamp)
    {
        m_data[key].insert({timestamp, value});
    }

    string get(string key, int timestamp)
    {
        auto it = m_data[key].upper_bound(timestamp);
        string res = (it == m_data[key].begin()) ? "" : prev(it)->second;
        return res;
    }
};
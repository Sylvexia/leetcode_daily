// 380. Insert Delete GetRandom O(1)

#include <bits/stdc++.h>

using namespace std;

class RandomizedSet
{
    vector<int> m_data;
    unordered_map<int, int> m_state;

public:
    RandomizedSet() {}

    bool insert(int val)
    {
        if (m_state.find(val) != m_state.end())
            return false;
        m_state[val] = m_data.size();
        m_data.push_back(val);
        return true;
    }

    bool remove(int val)
    {
        if (m_state.find(val) == m_state.end())
            return false;
        int last_ele = m_data.back();
        m_data[m_state[val]] = last_ele;
        m_data.pop_back();
        m_state[last_ele] = m_state[val];
        m_state.erase(val);
        return true;
    }

    int getRandom() { return m_data[rand() % m_data.size()]; }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
// 703. Kth Largest Element in a Stream

#include <bits/stdc++.h>
#include <iostream>

using namespace std;

class KthLargest
{
    int m_k;
    vector<int> m_data;

public:
    KthLargest(int k, vector<int> &nums)
        : m_k(k), m_data(nums.begin(), nums.end()) {}

    int add(int val)
    {
        m_data.push_back(val);
        nth_element(m_data.begin(), m_data.begin() + m_k - 1, m_data.end(), greater<int>());
        return m_data[m_k - 1];
    }
};

class KthLargest
{
    int m_k;
    priority_queue<int, vector<int>, greater<int>> m_data;

public:
    KthLargest(int k, vector<int> &nums)
        : m_k(k), m_data()
    {
        for (auto ele : nums)
        {
            m_data.push(ele);
            if (m_data.size() > m_k)
                m_data.pop();
        }
    }

    int add(int val)
    {
        m_data.push(val);
        if (m_data.size() > m_k)
            m_data.pop();
        return m_data.top();
    }
};

int main()
{
    vector<int> data{5, -1};
    KthLargest kth(3, data);
    kth.add(2);
    kth.add(1);
    kth.add(0);
    kth.add(-1);
}
// 2659. Make Array Empty

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    long long countOperationsToEmptyArray(vector<int> &nums)
    {
        long long res = 0;
        multiset<int> m_set(nums.begin(), nums.end());
        queue<int> q;
        for (int n : nums)
            q.push(n);

        while (q.size())
        {
            int min_ele = *min_element(m_set.begin(), m_set.end());
            if (min_ele != q.front())
            {
                int front = q.front();
                q.pop();
                q.push(front);
            }
            else
            {
                m_set.erase(q.front());
                q.pop();
            }
            res++;
        }

        return res;
    }
}; // this get tle, darn

class Solution
{
public:
    long long countOperationsToEmptyArray(vector<int> &nums)
    {
        long long res = nums.size();
        unordered_map<int, int> pos;
        for (int i = 0; i < nums.size(); i++)
            pos[nums[i]] = i;

        sort(nums.begin(), nums.end());

        for (int i = 1; i < nums.size(); i++)
        {
            if (pos[nums[i]] < pos[nums[i - 1]])
                res += nums.size() - i;
        }
        return res;
    }
};
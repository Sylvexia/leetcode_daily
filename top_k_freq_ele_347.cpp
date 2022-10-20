// 347. Top K Frequent Elements

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        unordered_map<int, int> count{};
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq{};

        for (int num : nums)
        {
            count[num]++;
        }

        for (auto &i : count)
        {
            pq.push({i.second, i.first});

            if (pq.size() > k)
                pq.pop();
        }

        vector<int> res;

        while (!pq.empty())
        {
            res.push_back(pq.top().second);
            pq.pop();
        }

        return res;
    }
};

int main()
{
    Solution sol;
    vector<int> data_vec = {1, 1, 2, 2, 2, 3, 3, 3, 3, 4, 4, 4, 4, 4, 4, 4, 4};
    vector<int> ans = sol.topKFrequent(data_vec, 2);
    for (auto i : ans)
    {
        cout << i << " ";
    }
}
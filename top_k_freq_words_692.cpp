// 692. Top K Frequent Words

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<string> topKFrequent(vector<string> &words, int k)
    {
        unordered_map<string, int> count{};

        for (auto str : words)
        {
            count[str]++;
        }

        auto comp = [&](const pair<string, int> &a, const pair<string, int> &b)
        {
            return a.second > b.second || (a.second == b.second && a.first < b.first);
        };// left freq < right freq, left string > right string

        // when reversed, left freq > right freq, left string < right string

        priority_queue<pair<string, int>, vector<pair<string, int>>, decltype(comp)> pq(comp);

        for (auto ele_pair : count)
        {
            pq.push(ele_pair);

            if (pq.size() > k)
                pq.pop();
        }// the largest freq on the top

        vector<string> res;

        while (!pq.empty())
        {
            res.push_back(pq.top().first);
            pq.pop();
        }

        // reverse the frequency
        reverse(res.begin(), res.end());

        return res;
    }
};
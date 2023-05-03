// 767. Reorganize String

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    string reorganizeString(string s)
    {
        unordered_map<char, int> ch_count;
        for (char ch : s)
            ch_count[ch]++;

        priority_queue<pair<int, char>> pq;
        for (auto &[ch, count] : ch_count)
            pq.push({count, ch});

        string res = "";
        auto [prev_count, prev_char] = make_pair(-1, '#');
        while (!pq.empty())
        {
            auto [front_count, front_char] = pq.top();
            pq.pop();
            res.push_back(front_char);

            if (prev_count > 0)
                pq.push({prev_count, prev_char});

            front_count--;
            tie(prev_count, prev_char) = {front_count, front_char};
        }

        if (s.length() != res.length())
            return "";

        return res;
    }
};
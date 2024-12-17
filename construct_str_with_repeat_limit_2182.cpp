// 2182. Construct String With Repeat Limit

#include <bits/stdc++.h>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
public:
    string repeatLimitedString(string s, int repeatLimit)
    {
        unordered_map<char, int> u_set;
        for (char ch : s)
            u_set[ch]++;

        priority_queue<char, vector<char>, less<>> pq;
        for (auto [key, _] : u_set)
            pq.push(key);

        string res;

        while (pq.size()) {
            char ch = pq.top();
            pq.pop();
            int count = u_set[ch];

            int use = min(count, repeatLimit);
            res.append(use, ch);

            u_set[ch] -= use;

            if (u_set[ch] > 0 and pq.size()) {
                char next = pq.top();
                pq.pop();

                res.push_back(next);
                u_set[next]--;

                if (u_set[next] > 0)
                    pq.push(next);

                pq.push(ch);
            }
        }

        return res;
    }
};
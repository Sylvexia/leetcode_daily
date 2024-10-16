// 1405. Longest Happy String

#include <bits/stdc++.h>
#include <queue>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
public:
    string longestDiverseString(int a, int b, int c)
    {
        priority_queue<pair<int, char>> pq;
        if (a)
            pq.push({a, 'a'});
        if (b)
            pq.push({b, 'b'});
        if (c)
            pq.push({c, 'c'});

        string res;
        while (pq.size() > 1) {
            auto [first_count, first_char] = pq.top();
            pq.pop();
            auto [second_count, second_char] = pq.top();
            pq.pop();

            int first_populate = first_count >= 2 ? 2 : 1;
            res += string(first_populate, first_char);
            first_count -= first_populate;

            int second_populate =
                (second_count >= 2 and second_count >= first_count) ? 2 : 1;
            res += string(second_populate, second_char);
            second_count -= second_populate;

            if (first_count > 0)
                pq.push({first_count, first_char});

            if (second_count > 0)
                pq.push({second_count, second_char});
        }
        if (pq.empty())
            return res;

        res += string(pq.top().first >= 2 ? 2 : 1, pq.top().second);
        return res;
    }
};
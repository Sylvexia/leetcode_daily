// 506. Relative Ranks

#include <bits/stdc++.h>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
public:
    vector<string> findRelativeRanks(vector<int> &score)
    {
        vector<string> rank_str{"Gold Medal", "Silver Medal", "Bronze Medal"};

        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       less<pair<int, int>>>
            pq;

        for (int i = 0; i < score.size(); i++)
            pq.push({score[i], i});

        vector<string> res(score.size());

        int rank = 1;
        while (!pq.empty()) {
            auto [score, index] = pq.top();
            pq.pop();

            if (rank <= 3)
                res[index] = rank_str[rank - 1];
            else
                res[index] = to_string(rank);

            rank++;
        }

        return res;
    }
};
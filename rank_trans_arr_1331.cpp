// 1331. Rank Transform of an Array

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
    vector<int> arrayRankTransform(vector<int> &arr)
    {
        auto comp = [](pair<int, int> &a, pair<int, int> &b) { return a > b; };

        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(comp)>
            pq(comp);

        for (int i = 0; i < arr.size(); i++)
            pq.push({arr[i], i});

        vector<int> res(arr.size());
        int rank = 0;
        int last_ele = -1;
        while (!pq.empty()) {
            auto [num, idx] = pq.top();
            pq.pop();

            rank = (last_ele == num) ? rank : rank + 1;
            res[idx] = rank;
            last_ele = num;
        }
        return res;
    }
};
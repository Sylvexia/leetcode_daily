// 2940. Find Building Where Alice and Bob Can Meet

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
    vector<int> leftmostBuildingQueries(vector<int> &heights,
                                        vector<vector<int>> &queries)
    {
        vector<vector<vector<int>>> store(heights.size());
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>>
            maxIndex;
        vector<int> res(queries.size(), -1);

        for (int q = 0; q < queries.size(); q++) {
            int a = queries[q][0];
            int b = queries[q][1];
            if (a < b and heights[a] < heights[b])
                res[q] = b;
            else if (a > b and heights[a] > heights[b])
                res[q] = a;
            else if (a == b)
                res[q] = a;
            else
                store[max(a, b)].push_back({max(heights[a], heights[b]), q});
        }

        for (int i = 0; i < heights.size(); i++) {
            while (!maxIndex.empty() and maxIndex.top()[0] < heights[i]) {
                res[maxIndex.top()[1]] = i;
                maxIndex.pop();
            }
            for (auto &ele : store[i])
                maxIndex.push(ele);
        }
        return res;
    }
};
// 2285. Maximum Total Importance of Roads

#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
public:
    long long maximumImportance(int n, vector<vector<int>> &roads)
    {
        unordered_map<int, int> count;

        for (auto &road : roads) {
            count[road[0]]++;
            count[road[1]]++;
        }

        vector<int> edges;
        for (auto &[key, value] : count)
            edges.push_back(value);

        sort(edges.rbegin(), edges.rend());

        long long int res = 0;

        for (int e : edges)
            res += long(e) * n--;

        return res;
    }
};
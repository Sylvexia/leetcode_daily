// 2418. Sort the People

#include <bits/stdc++.h>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
public:
    vector<string> sortPeople(vector<string> &names, vector<int> &heights)
    {
        vector<pair<int, int>> data;
        for (int i = 0; i < heights.size(); i++)
            data.push_back({heights[i], i});

        sort(data.rbegin(), data.rend());

        vector<string> res;
        for (auto [h, i] : data)
            res.push_back(names[i]);

        return res;
    }
};
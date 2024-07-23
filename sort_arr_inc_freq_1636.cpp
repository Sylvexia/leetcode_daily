// 1636. Sort Array by Increasing Frequency

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
    vector<int> frequencySort(vector<int> &nums)
    {
        unordered_map<int, int> u_map;
        for (int n : nums)
            u_map[n]++;

        vector<pair<int, int>> data(u_map.begin(), u_map.end());

        auto comp = [](pair<int, int> &a, pair<int, int> &b) {
            if (a.second == b.second)
                return a.first > b.first;
            return a.second < b.second;
        };
        sort(data.begin(), data.end(), comp);

        vector<int> res;
        for (auto &[key, count] : data) {
            for (int i = 0; i < count; i++)
                res.push_back(key);
        }

        return res;
    }
};
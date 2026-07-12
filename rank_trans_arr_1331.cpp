// 1331. Rank Transform of an Array

#include <iostream>

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
        int n = arr.size();
        vector<pair<int, int>> vec;
        for (int i = 0; i < n; i++)
            vec.push_back({arr[i], i});
        ranges::sort(vec);
        vector<int> res(n);
        int rank = 0;
        int prev = INT_MAX;
        for (auto [val, idx] : vec) {
            rank += prev != val;
            res[idx] = rank;
            prev = val;
        }
        return res;
    }
};
// 1476. Subrectangle Queries

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
    vector<vector<int>> findMatrix(vector<int> &nums)
    {
        unordered_map<int, int> u_map;
        for (int n : nums)
            u_map[n]++;

        int maxFreq = -1;
        for (auto [key, val] : u_map) {
            maxFreq = max(maxFreq, val);
        }

        vector<vector<int>> res;
        for (int j = 0; j < maxFreq; j++) {
            vector<int> temp;
            for (auto &[key, val] : u_map) {
                if (val > 0) {
                    temp.push_back(key);
                    val--;
                }
            }
            res.push_back(temp);
        }
        return res;
    }
};
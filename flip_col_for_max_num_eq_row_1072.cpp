// 1072. Flip Columns For Maximum Number of Equal Rows

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
    int maxEqualRowsAfterFlips(vector<vector<int>> &matrix)
    {
        int m = matrix.size();
        int n = matrix[0].size();
        unordered_map<string, int> u_map;
        for (auto &r : matrix) {
            string str;
            string comp;
            for (auto c : r) {
                str += (c + '0');
                comp += ((c ^ 1) + '0');
            }
            u_map[str]++;
            u_map[comp]++;
        }

        int res = 0;
        for (auto [key, count] : u_map)
            res = max(res, count);
        return res;
    }
};
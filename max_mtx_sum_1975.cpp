// 1975. Maximum Matrix Sum

#include <bits/stdc++.h>
#include <climits>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
public:
    long long maxMatrixSum(vector<vector<int>> &matrix)
    {
        int abs_min = INT_MAX;
        int neg_count = 0;
        long long abs_sum = 0;
        for (auto &r : matrix) {
            for (auto c : r) {
                abs_min = min(abs_min, abs(c));
                neg_count += (c < 0);
                abs_sum += abs(c);
            }
        }

        return (neg_count % 2) ? (abs_sum - 2 * abs_min) : abs_sum;
    }
};
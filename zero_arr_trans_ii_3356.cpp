// 3356. Zero Array Transformation II

#include <bits/stdc++.h>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
public:
    int minZeroArray(vector<int> &nums, vector<vector<int>> &queries)
    {
        int n = nums.size();
        vector<int> sweep(n + 1);

        int res = 0;
        int sum = 0;
        for (int i = 0; i < n; i++) {
            while (sum + sweep[i] < nums[i]) {
                if (res == queries.size())
                    return -1;

                int l = queries[res][0];
                int r = queries[res][1];
                int val = queries[res][2];
                res++;

                if (r < i)
                    continue;
                sweep[max(l, i)] += val;
                sweep[r + 1] -= val;
            }
            sum += sweep[i];
        }
        return res;
    }
};
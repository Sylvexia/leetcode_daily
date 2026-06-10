// 3691. Maximum Total Subarray Value II

#include <algorithm>
#include <bit>
#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class LUT
{
    vector<vector<int>> min_vec, max_vec;

public:
    LUT(const vector<int>& nums)
    {
        int n = nums.size();
        int w = bit_width((unsigned)n);

        min_vec.assign(w, vector<int>(n));
        max_vec.assign(w, vector<int>(n));

        for (int i = 0; i < n; i++) {
            min_vec[0][i] = nums[i];
            max_vec[0][i] = nums[i];
        }

        for (int i = 1; i < w; i++) {
            int len = 1 << i;
            int half = 1 << (i - 1);

            for (int j = 0; j + len <= n; j++) {
                min_vec[i][j] = min(min_vec[i - 1][j],
                                    min_vec[i - 1][j + half]);

                max_vec[i][j] = max(max_vec[i - 1][j],
                                    max_vec[i - 1][j + half]);
            }
        }
    }

    int query(int l, int r)
    {
        int len = r - l;
        int k = bit_width((unsigned)len) - 1;

        int mn = min(min_vec[k][l], min_vec[k][r - (1 << k)]);
        int mx = max(max_vec[k][l], max_vec[k][r - (1 << k)]);

        return mx - mn;
    }
};

class Solution
{
public:
    long long maxTotalValue(vector<int>& nums, int k)
    {
        int n = nums.size();
        long long res = 0;

        LUT lut(nums);

        priority_queue<tuple<int, int, int>> pq;

        for (int l = 0; l < n; l++) {
            pq.push({lut.query(l, n), l, n});
        }

        while (k-- && !pq.empty()) {
            auto [val, l, r] = pq.top();
            pq.pop();

            res += val;

            if (r - l > 1) {
                pq.push({lut.query(l, r - 1), l, r - 1});
            }
        }

        return res;
    }
};
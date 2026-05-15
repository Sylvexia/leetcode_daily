// 3424. Minimum Cost to Make Arrays Identical

#include <bits/stdc++.h>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();


class Solution
{
public:
    long long minCost(vector<int> &arr, vector<int> &brr, long long k)
    {
        int n = arr.size();
        long long res = 0;
        for (int i = 0; i < n; i++) {
            res += abs((long long) arr[i] - brr[i]);
        }

        long long res2 = 0;
        sort(arr.begin(), arr.end());
        sort(brr.begin(), brr.end());

        for (int i = 0; i < n; i++) {
            res2 += abs((long long) arr[i] - brr[i]);
        }
        return min(res, res2 + k);
    }
};
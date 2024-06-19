// 1482. Minimum Number of Days to Make m Bouquets

#include <bits/stdc++.h>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
public:
    int minDays(vector<int> &bloomDay, int m, int k)
    {
        int n = bloomDay.size();
        int l = 1;
        int r = 1e9;

        if (m * (long long int)k > n)
            return -1;

        while (l < r) {
            int mid = l + (r - l) / 2;
            int flow = 0;
            int bouq = 0;
            
            for (int j = 0; j < n; j++) {
                if (bloomDay[j] > mid)
                    flow = 0;
                else if (++flow >= k) {
                    bouq++;
                    flow = 0;
                }
            }
            if (bouq < m)
                l = mid + 1;
            else
                r = mid;
        }
        return l;
    }
};
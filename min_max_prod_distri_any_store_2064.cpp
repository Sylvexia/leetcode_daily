// 2064. Minimized Maximum of Products Distributed to Any Store

#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
    int cal(vector<int> &quantities, int target)
    {
        int res = 0;
        for (int q : quantities)
            res += q / target + (q % target != 0);
        return res;
    }

public:
    int minimizedMaximum(int n, vector<int> &quantities)
    {
        int l = 1;
        int r = *max_element(quantities.begin(), quantities.end());

        while (l < r) {
            int m = l + (r - l) / 2;
            if (cal(quantities, m) <= n)
                r = m;
            else
                l = m + 1;
        }
        return l;
    }
};
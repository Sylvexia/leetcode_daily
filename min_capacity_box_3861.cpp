// 3861. Minimum Capacity Box

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
    int minimumIndex(vector<int> &capacity, int itemSize)
    {
        int n = capacity.size();
        int res = -1;
        int min_capa = INT_MAX;
        for (int i = 0; i < n; i++) {
            int cur_capa = capacity[i];
            if (cur_capa >= itemSize and cur_capa < min_capa) {
                res = i;
                min_capa = cur_capa;
            }
        }
        return res;
    }
};
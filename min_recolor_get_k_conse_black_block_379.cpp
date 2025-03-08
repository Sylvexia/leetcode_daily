// 2379. Minimum Recolors to Get K Consecutive Black Blocks

#include <bits/stdc++.h>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
public:
    int minimumRecolors(string blocks, int k)
    {
        int res = 0;
        for (int i = 0; i < k; i++)
            res += blocks[i] != 'B';

        int cur = res;
        for (int l = 0, r = l + k; r < blocks.size(); l++, r++) {
            cur -= blocks[l] != 'B';
            cur += blocks[r] != 'B';
            res = min(res, cur);
        }
        return res;
    }
};
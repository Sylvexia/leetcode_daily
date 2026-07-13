// 2673. Make Costs of Paths Equal in a Binary Tree

#include <iostream>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
public:
    int minIncrements(int n, vector<int> &cost)
    {
        int res = 0;
        function<int(int)> dfs = [&](int i) {
            if (i >= cost.size())
                return 0;
            int l = dfs(i * 2 + 1);
            int r = dfs(i * 2 + 2);
            res += abs(l - r);
            return max(l, r) + cost[i];
        };
        dfs(0);
        return res;
    }
};
// 3028. Ant on the Boundary

#include <bits/stdc++.h>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
public:
    int returnToBoundaryCount(vector<int> &nums)
    {
        int cur = 0;
        int res = 0;
        for (int n : nums) {
            cur += n;
            res += cur == 0;
        }
        return res;
    }
};
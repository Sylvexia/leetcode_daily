// 1051. Height Checker

#include <bits/stdc++.h>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
public:
    int heightChecker(vector<int> &heights)
    {
        vector<int> sorted(heights.begin(), heights.end());
        sort(sorted.begin(), sorted.end());

        int res = 0;
        for (int i = 0; i < heights.size(); i++) {
            res += heights[i] != sorted[i];
        }

        return res;
    }
};
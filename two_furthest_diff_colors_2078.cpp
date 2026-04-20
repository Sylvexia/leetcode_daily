// 2078. Two Furthest Houses With Different Colors

#include <bits/stdc++.h>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
public:
    int maxDistance(vector<int> &colors)
    {
        int n = colors.size();
        for (int i = n - 1; i > 0; i--) {
            for (int j = 0; j + i < n; j++) {
                if (colors[j] != colors[j + i])
                    return i;
            }
        }
        return -1;
    }
};
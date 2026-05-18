// 3285. Find Indices of Stable Mountains

#include <bits/stdc++.h>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
public:
    vector<int> stableMountains(vector<int> &height, int threshold)
    {
        int n = height.size();
        vector<int> res;
        for (int i = 1; i < n; i++) {
            if (height[i - 1] > threshold)
                res.push_back(i);
        }
        return res;
    }
};
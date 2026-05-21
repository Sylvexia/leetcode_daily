// 3047. Find the Largest Area of Square Inside Two Rectangles

#include <bits/stdc++.h>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
public:
    long long largestSquareArea(vector<vector<int>> &bottomLeft,
                                vector<vector<int>> &topRight)
    {
        int n = bottomLeft.size();
        long long res = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                long long left = max(bottomLeft[i][0], bottomLeft[j][0]);
                long long right = min(topRight[i][0], topRight[j][0]);
                long long bottom = max(bottomLeft[i][1], bottomLeft[j][1]);
                long long top = min(topRight[i][1], topRight[j][1]);
                long long width = right - left;
                long long height = top - bottom;
                if (width > 0 and height > 0) {
                    long long side = min(width, height);
                    res = max(res, side * side);
                }
            }
        }
        return res;
    }
};
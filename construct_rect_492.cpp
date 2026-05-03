// 492. Construct the Rectangle

#include <bits/stdc++.h>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
public:
    vector<int> constructRectangle(int area)
    {
        int base = sqrt(area);
        for (int w = base; w > 0; w--) {
            int l = area / w;
            if (w * l == area)
                return {l, w};
        }
        return {area, 1};
    }
};
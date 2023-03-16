// 84. Largest Rectangle in Histogram

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int largestRectangleArea(vector<int> &heights)
    {
        stack<int> incre_i;
        int res = 0;

        for (int i = 0; i <= heights.size(); i++)
        {
            while (incre_i.size() and
                   (i == heights.size() or heights[i] < heights[incre_i.top()]))
            {
                int height = heights[incre_i.top()];
                incre_i.pop();
                int width = (incre_i.size()) ? i - incre_i.top() - 1 : i;
                res = max(res, height * width);
            }
            incre_i.push(i);
        }
        return res;
    }
};
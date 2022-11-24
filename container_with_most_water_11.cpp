// 11. Container With Most Water

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        int l = 0, r = height.size() - 1, capacity = 0;

        while (l < r)
        {
            capacity = max(capacity, min(height[l], height[r]) * (r - l));

            if (height[l] < height[r])
                l++;
            else if (height[l] > height[r])
                r--;
            else
            {
                l++;
                r--;
            }
        }

        return capacity;
    }
};
// 2057. Smallest Index With Equal Value

#include <bits/stdc++.h>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
public:
    int smallestEqual(vector<int> &nums)
    {
        for (int i = 0; i < nums.size(); i++) {
            if (i % 10 == nums[i])
                return i;
        }
        return -1;
    }
};
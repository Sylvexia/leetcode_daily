// 1608. Special Array With X Elements Greater Than or Equal X

#include <bits/stdc++.h>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
public:
    int specialArray(vector<int> &nums)
    {
        int res = 0;
        for (; res <= nums.size(); res++) {
            int count = 0;

            for (int num : nums) {
                if (num >= res)
                    count++;
            }
            if (count == res)
                return res;
        }
        return -1;
    }
};
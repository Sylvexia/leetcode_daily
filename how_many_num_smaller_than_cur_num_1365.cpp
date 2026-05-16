// 1365. How Many Numbers Are Smaller Than the Current Number

#include <bits/stdc++.h>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
public:
    vector<int> smallerNumbersThanCurrent(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> res(n);

        for (int i = 0; i < n; i++) {
            int cnt = 0;
            for (int j = 0; j < n; j++)
                cnt += nums[i] > nums[j];
            res[i] = cnt;
        }
        return res;
    }
};
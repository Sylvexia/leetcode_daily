// 962. Maximum Width Ramp

#include <bits/stdc++.h>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
public:
    int maxWidthRamp(vector<int> &nums)
    {
        stack<int> stk;
        for (int i = 0; i < nums.size(); i++) {
            if (stk.empty() or nums[stk.top()] > nums[i])
                stk.push(i);
        }
        int res = 0;
        for (int i = nums.size() - 1; i >= 0; i--) {
            while (!stk.empty() and nums[stk.top()] <= nums[i]) {
                res = max(res, i - stk.top());
                stk.pop();
            }
        }
        return res;
    }
};
// 3660. Jump Game IX

#include <bits/stdc++.h>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
public:
    vector<int> maxValue(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> pre(n), suf(n), res(n);

        pre[0] = nums[0];
        for (int i = 1; i < n; i++)
            pre[i] = max(pre[i - 1], nums[i]);

        suf[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; i--)
            suf[i] = min(suf[i + 1], nums[i]);

        res[n - 1] = pre[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            if (pre[i] > suf[i + 1]) {
                res[i] = res[i + 1];
            } else
                res[i] = pre[i];
        }

        return res;
    }
};
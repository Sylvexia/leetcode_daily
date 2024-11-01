// 1671. Minimum Number of Removals to Make Mountain Array

#include <bits/stdc++.h>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
public:
    int minimumMountainRemovals(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> lis(n, 1), lds(n, 1);

        for (int i = 0; i < n; i++) {
            for (int j = i - 1; j >= 0; j--) {
                if (nums[i] > nums[j]) {
                    lis[i] = max(lis[i], lis[j] + 1);
                }
            }
        }

        for (int i = n - 1; i >= 0; i--) {
            for (int j = i + 1; j < n; j++) {
                if (nums[i] > nums[j])
                    lds[i] = max(lds[i], lds[j] + 1);
            }
        }

        int res = INT_MAX;
        for (int i = 0; i < n; i++) {
            if (lis[i] > 1 and lds[i] > 1)
                res = min(res, n - lis[i] - lds[i] + 1);
        }
        return res;
    }
};
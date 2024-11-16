// 3254. Find the Power of K-Size Subarrays I

#include <bits/stdc++.h>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
public:
    vector<int> resultsArray(vector<int> &nums, int k)
    {
        int n = nums.size();
        vector<int> res;
        for (int i = 0; i < n - k + 1; i++) {
            bool isCon = true;
            for (int j = 0; j < k - 1; j++) {
                if (nums[i + j] + 1 != nums[i + j + 1]) {
                    isCon = false;
                    break;
                }
            }
            res.push_back(isCon ? nums[i + k - 1] : -1);
        }
        return res;
    }
};
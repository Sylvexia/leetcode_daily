// 2903. Find Indices With Index and Value Difference I

#include <bits/stdc++.h>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
public:
    vector<int> findIndices(vector<int> &nums,
                            int indexDifference,
                            int valueDifference)
    {
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                if (abs(i - j) >= indexDifference and
                    abs(nums[i] - nums[j]) >= valueDifference)
                    return {i, j};
            }
        }
        return {-1, -1};
    }
};
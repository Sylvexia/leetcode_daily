// 2089. Find Target Indices After Sorting Array

#include <bits/stdc++.h>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
public:
    vector<int> targetIndices(vector<int> &nums, int target)
    {
        vector<int> res;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (nums[i] == target)
                res.push_back(i);
        }
        return res;
    }
};
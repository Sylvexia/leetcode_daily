// 448. Find All Numbers Disappeared in an Array

#include <bits/stdc++.h>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
public:
    vector<int> findDisappearedNumbers(vector<int> &nums)
    {
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (nums[abs(nums[i]) - 1] > 0)
                nums[abs(nums[i]) - 1] *= -1;
        }
        vector<int> res;
        for (int i = 0; i < n; i++)
            if (nums[i] > 0)
                res.push_back(i+1);

        return res;
    }
};
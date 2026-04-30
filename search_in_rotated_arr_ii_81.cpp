// 81. Search in Rotated Sorted Array II

#include <bits/stdc++.h>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
public:
    bool search(vector<int> &nums, int target)
    {
        int l = 0;
        int r = nums.size() - 1;

        while (l <= r) {
            int m = l + (r - l) / 2;

            if (nums[m] == target)
                return true;

            if (nums[l] < nums[m]) {
                if (target >= nums[l] and target < nums[m])
                    r = m - 1;
                else
                    l = m + 1;

            } else if (nums[l] > nums[m]) {
                if (target > nums[m] and target <= nums[r])
                    l = m + 1;
                else
                    r = m - 1;
            } else
                l++;
        }
        return false;
    }
};
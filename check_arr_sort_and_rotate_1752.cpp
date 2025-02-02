// 1752. Check if Array Is Sorted and Rotated

#include <bits/stdc++.h>
#include <climits>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
public:
    bool check(vector<int> &nums)
    {
        int n = nums.size();
        if (n < 2)
            return true;
        // int start_index = min_element(nums.begin(), nums.end()) -
        // nums.begin();

        for (int start_index = 0; start_index < n; start_index++) {
            bool cur = true;
            for (int i = 0; i < n - 1; i++) {
                int cur_i = (start_index + i) % n;
                int next_i = (start_index + i + 1) % n;
                if (nums[cur_i] > nums[next_i]) {
                    cur = false;
                    break;
                }
            }
            if (cur)
                return true;
        }
        return false;
    }
};
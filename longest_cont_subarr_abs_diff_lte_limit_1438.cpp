// 1438. Longest Continuous Subarray With Absolute Diff Less Than or Equal to
// Limit

#include <bits/stdc++.h>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
public:
    int longestSubarray(vector<int> &nums, int limit)
    {
        deque<int> maxd, mind;
        int i = 0, j;
        for (j = 0; j < nums.size(); j++) {
            while (!maxd.empty() and nums[j] > maxd.back())
                maxd.pop_back();
            while (!mind.empty() and nums[j] < mind.back())
                mind.pop_back();
            maxd.push_back(nums[j]);
            mind.push_back(nums[j]);
            if (maxd.front() - mind.front() > limit) {
                if (maxd.front() == nums[i])
                    maxd.pop_front();
                if (mind.front() == nums[i])
                    mind.pop_front();
                i++;
            }
        }
        return j - i;
    }
};
// 239. Sliding Window Maximum

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        vector<int> res;
        deque<int> mono_decre;

        for (int i = 0; i < nums.size(); i++)
        {
            if (mono_decre.size() and mono_decre.front() == i - k)
                mono_decre.pop_front(); // pop if out of window
            while (mono_decre.size() and nums[mono_decre.back()] < nums[i])
                mono_decre.pop_back();
            mono_decre.push_back(i);
            if (i >= k - 1)
                res.push_back(nums[mono_decre.front()]);
        }
        return res;
    }
};
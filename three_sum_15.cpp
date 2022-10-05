// 15. 3Sum

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        vector<vector<int>> res{};
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++)
        {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;

            int l = i + 1, r = nums.size() - 1;

            while (l < r)
            {
                int sum = nums[i] + nums[l] + nums[r];

                if (sum < 0)
                    l++;
                else if (sum > 0)
                    r--;
                else
                {
                    res.push_back({nums[i], nums[l], nums[r]});

                    while (l + 1 < r && nums[l] == nums[l + 1])
                        l++;
                    while (l < r - 1 && nums[r] == nums[r - 1])
                        r--;
                    l++, r--;
                }
            }
        }

        return res;
    }
};

// ch2 5 7 8 10 11 12
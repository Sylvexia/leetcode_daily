// 135. Candy

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int candy(vector<int> &ratings)
    {
        vector<int> nums(ratings.size(), 1);
        for (int i = 1; i < nums.size(); i++) {
            if (ratings[i] > ratings[i - 1])
                nums[i] = nums[i - 1] + 1;
        }

        for (int i = nums.size() - 1; i > 0; i--) {
            if (ratings[i - 1] > ratings[i])
                nums[i - 1] = max(nums[i - 1], nums[i] + 1);
        }

        int res = 0;
        for (int num : nums) {
            res += num;
        }

        return res;
    }
};
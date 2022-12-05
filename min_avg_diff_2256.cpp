// 2256. Minimum Average Difference

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int minimumAverageDifference(vector<int> &nums)
    {
        if (nums.size() == 1)
            return 0;
        long long int sum = accumulate(nums.begin(), nums.end(), (long long int)0);
        long long int l = 0;
        long long int r = sum;
        int l_size = 0;
        int r_size = nums.size();
        long long int min = LONG_LONG_MAX;
        int index = -1;
        for (int i = 0; i < nums.size(); i++)
        {
            l += nums[i];
            r -= nums[i];
            l_size++;
            r_size--;

            long long int l_res = (l_size == 0) ? 0 : l / l_size;
            long long int r_res = (r_size == 0) ? 0 : r / r_size;

            long long int res = abs(l_res - r_res);
            if (res < min)
            {
                index = i;
                min = res;
            }
        }

        return index;
    }
};

int main()
{
    Solution sol;
    vector<int> vec = {2, 5, 3, 9, 5, 3};
    sol.minimumAverageDifference(vec);
    return 0;
}
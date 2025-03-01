// 2460. Apply Operations to an Array

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<int> applyOperations(vector<int> &nums)
    {
        int n = nums.size();
        for (int i = 0; i < n - 1; i++) {
            if (nums[i] == nums[i + 1]) {
                nums[i] *= 2;
                nums[i + 1] = 0;
            }
        }

        for (int i = 0; i < n; i++) {
            if (nums[i] != 0)
                continue;
            int j = i + 1;
            while (j < n and nums[j] == 0)
                j++;
            if (j == n)
                break;
            swap(nums[i], nums[j]);
        }


        return nums;
    }
};
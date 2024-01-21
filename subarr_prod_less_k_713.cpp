// 713. Subarray Product Less Than K

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int numSubarrayProductLessThanK(vector<int> &nums, int k)
    {
        int res = 0;
        int prod = 1;
        for (int i = 0, j = 0; j < nums.size(); j++) {
            prod *= nums[j];
            while (i <= j and prod >= k)
                prod /= nums[i++];

            res += j - i + 1;
        }

        return res;
    }
};

int main()
{
    Solution sol;
    vector<int> data{57, 44, 92, 28, 66, 60, 37, 33, 52, 38, 29, 76, 8, 75, 22};
    int k = 18;
    cout << sol.numSubarrayProductLessThanK(data, k);
}
// 41. First Missing Positive

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int firstMissingPositive(vector<int> &nums)
    {
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            while (nums[i] <= n and nums[i] > 0 and
                   nums[i] != nums[nums[i] - 1]) {
                swap(nums[i], nums[nums[i] - 1]);
            }
        }


        for (int i = 1; i <= n; i++) {
            if (nums[i - 1] != i)
                return i;
        }

        return n + 1;
    }
};

int main()
{
    Solution sol;
    vector<int> data{3, 4, -1, 1};
    cout << sol.firstMissingPositive(data);
}
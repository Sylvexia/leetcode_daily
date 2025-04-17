// 2176. Count Equal and Divisible Pairs in an Array

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int countPairs(vector<int> &nums, int k)
    {
        int n = nums.size();
        int res = 0;
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                bool eq = nums[i] == nums[j];
                bool div = (i * j) % k == 0;
                res += eq && div;
            }
        }
        return res;
    }
};
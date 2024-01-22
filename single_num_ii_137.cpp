// 137. Single Number II

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
        int ones = 0;
        int twos = 0;
        for (int i = 0; i < nums.size(); i++) {
            ones = (ones ^ nums[i]) & ~twos;
            twos = (twos ^ nums[i]) & ~ones;
        }
        return ones;
    }
};
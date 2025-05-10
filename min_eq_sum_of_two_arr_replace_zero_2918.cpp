// 2918. Minimum Equal Sum of Two Arrays After Replacing Zeros

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    long long minSum(vector<int> &nums1, vector<int> &nums2)
    {
        long long target1 = 0, target2 = 0;
        bool hasZero1 = false, hasZero2 = false;

        for (auto n : nums1) {
            target1 += n;
            target1 += (n == 0);
            hasZero1 |= n == 0;
        }
        for (auto n : nums2) {
            target2 += n;
            target2 += (n == 0);
            hasZero2 |= n == 0;
        }

        if (target1 > target2 and !hasZero2)
            return -1;
        if (target2 > target1 and !hasZero1)
            return -1;

        return max(target1, target2);
    }
};
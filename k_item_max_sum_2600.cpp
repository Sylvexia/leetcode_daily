// 2600. K Items With the Maximum Sum

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int kItemsWithMaximumSum(int numOnes, int numZeros, int numNegOnes, int k)
    {
        int one = min(k, numOnes);
        int zeros = min(k - one, numZeros);
        int neg = min(k - one - zeros, numNegOnes);
        return one - neg;
    }
};
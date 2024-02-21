// 201. Bitwise AND of Numbers Range

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int rangeBitwiseAnd(int left, int right)
    {
        int n = right;
        while (n - 1 >= left) {
            n = n & (n - 1);
        }
        return n;
    }
};
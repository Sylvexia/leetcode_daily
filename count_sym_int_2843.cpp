// 2843. Count Symmetric Integers

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int countSymmetricIntegers(int low, int high)
    {
        int res = 0;
        for (int i = low; i <= high; i++) {
            string numStr = to_string(i);
            if (numStr.size() % 2 == 1)
                continue;

            int left = 0, right = 0;
            for (int j = 0; j < numStr.size() / 2; j++) {
                left += numStr[j];
                right += numStr[numStr.size() - j - 1];
            }
            res += (left == right);
        }
        return res;
    }
};
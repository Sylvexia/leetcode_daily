// 278. First Bad Version

#include <bits/stdc++.h>

using namespace std;

// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

bool isBadVersion(int version)
{
    ;
}

class Solution
{
public:
    int firstBadVersion(int n)
    {
        int l = 0, r = n;
        while (l < r)
        {
            int m = l + (r - l) / 2;
            if (isBadVersion(m))
                r = m;
            else
                l = m + 1;
        }
        return l;
    }
};
// 1095. Find in Mountain Array

#include <bits/stdc++.h>

using namespace std;

// You should not implement it, or speculate about its implementation
class MountainArray
{
public:
    int get(int index);
    int length();
};

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
public:
    int findInMountainArray(int target, MountainArray &mountainArr)
    {
        int l = 1;
        int r = mountainArr.length() - 2;
        int peak = 0;
        while (l <= r) {
            int m = l + (r - l) / 2;
            int left = mountainArr.get(m - 1);
            int mid = mountainArr.get(m);
            int right = mountainArr.get(m + 1);
            if (left < mid and mid < right)
                l = m + 1;
            else if (left > mid and mid > right)
                r = m - 1;
            else {
                peak = m;
                break;
            }
        }

        l = 0;
        r = peak - 1;
        while (l <= r) {
            int m = l + (r - l) / 2;
            int val = mountainArr.get(m);
            if (val > target)
                r = m - 1;
            else if (val < target)
                l = m + 1;
            else
                return m;
        }

        l = peak;
        r = mountainArr.length() - 1;
        while (l <= r) {
            int m = l + (r - l) / 2;
            int val = mountainArr.get(m);
            if (val < target)
                r = m - 1;
            else if (val > target)
                l = m + 1;
            else
                return m;
        }
        return -1;
    }
};
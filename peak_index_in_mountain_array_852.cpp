// 852. Peak Index in a Mountain Array

#include <bits/stdc++.h>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
public:
    int peakIndexInMountainArray(vector<int> &arr)
    {
        int l = 1;
        int r = arr.size() - 2;

        while (l <= r) {
            int m = l + (r - l) / 2;
            int right = arr[m + 1];
            int mid = arr[m];
            int left = arr[m - 1];
            if (left < mid and mid < right)
                l = m + 1;
            else if (left > mid and mid > right)
                r = m - 1;
            else
                return m;
        }
        return -1;
    }
};
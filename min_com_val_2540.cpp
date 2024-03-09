// 2540. Minimum Common Value

#include <bits/stdc++.h>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
public:
    int getCommon(vector<int> &nums1, vector<int> &nums2)
    {
        int l = 0, r = 0;
        while (l < nums1.size() and r < nums2.size()) {
            if (nums1[l] == nums2[r])
                return nums1[l];
            else if (nums1[l] < nums2[r])
                l++;
            else
                r++;
        }

        return -1;
    }
};
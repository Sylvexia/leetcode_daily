// 1855. Maximum Distance Between a Pair of Values

#include <bits/stdc++.h>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
public:
    int maxDistance(vector<int> &nums1, vector<int> &nums2)
    {
        int res = 0;
        int i = 0;
        int j = 0;
        while (i < nums1.size() and j < nums2.size()) {
            if (i <= j and nums1[i] <= nums2[j]) {
                res = max(res, j - i);
                j++;
            } else if (i <= j)
                i++;
            else
                j++;
        }
        return res;
    }
};
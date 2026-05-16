// 3131. Find the Integer Added to Array I

#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
public:
    int addedInteger(vector<int> &nums1, vector<int> &nums2)
    {
        return *min_element(nums2.begin(), nums2.end()) -
               *min_element(nums1.begin(), nums1.end());
    }
};
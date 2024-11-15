// 1574. Shortest Subarray to be Removed to Make Array Sorted

#include <bits/stdc++.h>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
public:
    int findLengthOfShortestSubarray(vector<int> &arr)
    {
        int n = arr.size();
        int r = n - 1;
        while (r > 0 and arr[r - 1] <= arr[r])
            r--;
        int res = r;
        for (int l = 0; l < r and (l == 0 or arr[l - 1] <= arr[l]); l++) {
            while (r < n and arr[r] < arr[l])
                r++;
            res = min(res, r - l - 1);
        }
        return res;
    }
};
// 1846. Maximum Element After Decreasing and Rearranging

#include <iostream>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int> &arr)
    {
        ranges::sort(arr);
        int res = 1;
        for (int i = 1; i < arr.size(); i++) {
            if (arr[i] >= res + 1)
                res++;
        }
        return res;
    }
};
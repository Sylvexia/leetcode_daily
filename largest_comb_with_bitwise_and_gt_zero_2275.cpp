// 2275. Largest Combination With Bitwise AND Greater Than Zero

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
    int largestCombination(vector<int> &candidates)
    {
        array<int, 32> arr;
        for (int i = 0; i < 32; i++) {
            int mask = 1 << i;
            int count = 0;
            for (int ele : candidates) {
                bool mask_res = mask & ele;
                count += mask_res;
            }
            arr[i] = count;
        }
        return *max_element(arr.begin(), arr.end());
    }
};
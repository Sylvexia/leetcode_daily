// 1502. Can Make Arithmetic Progression From Sequence

#include <bits/stdc++.h>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();


class Solution
{
public:
    bool canMakeArithmeticProgression(vector<int> &arr)
    {
        sort(arr.begin(), arr.end());
        for (int i = 0; i < arr.size() - 2; i++) {
            if (arr[i] - arr[i + 1] != arr[i + 1] - arr[i + 2])
                return false;
        }
        return true;
    }
};
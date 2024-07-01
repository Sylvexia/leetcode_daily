// 1550. Three Consecutive Odds

#include <bits/stdc++.h>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
public:
    bool threeConsecutiveOdds(vector<int> &arr)
    {
        int odd_count = 0;
        for (int i = 0; i < arr.size() and odd_count < 3; i++) {
            odd_count = (arr[i] % 2 == 1) ? odd_count + 1 : 0;
        }
        return odd_count == 3;
    }
};
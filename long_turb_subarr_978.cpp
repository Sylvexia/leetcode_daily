// 978. Longest Turbulent Subarray

#include <bits/stdc++.h>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

enum State { Increase, Decrease, Equal };

class Solution
{
    State getState(int a, int b)
    {
        if (a > b)
            return Decrease;
        else if (a < b)
            return Increase;
        else
            return Equal;
    }

public:
    int maxTurbulenceSize(vector<int> &arr)
    {
        int res = 1;
        int cur = 1;
        int n = arr.size();
        if (n == 1)
            return 1;

        State state = Equal;
        for (int i = 0; i < n - 1; i++) {
            State curState = getState(arr[i], arr[i + 1]);
            if ((state == Decrease and curState == Increase) or
                (state == Increase and curState == Decrease)) {
                cur++;
            } else if (curState == Equal) {
                cur = 1;
            } else
                cur = 2;

            res = max(res, cur);
            state = curState;
        }
        return res;
    }
};
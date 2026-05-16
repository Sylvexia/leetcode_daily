// 1342. Number of Steps to Reduce a Number to Zero

#include <bits/stdc++.h>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
public:
    int numberOfSteps(int num)
    {
        int res = 0;
        while (num) {
            if (num % 2)
                num -= 1;
            else
                num /= 2;
            res++;
        }
        return res;
    }
};
// 1780. Check if Number is a Sum of Powers of Three

#include <bits/stdc++.h>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
public:
    bool checkPowersOfThree(int n)
    {
        while (n) {
            int mod = n % 3;
            if (mod > 1)
                return false;
            n /= 3;
        }

        return true;
    }
};
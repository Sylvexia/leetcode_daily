// 3622. Check Divisibility by Digit Sum and Product

#include <bits/stdc++.h>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
public:
    bool checkDivisibility(int n)
    {
        string s = to_string(n);
        int prod = 1;
        int sum = 0;
        for (char c : s) {
            int num = c - '0';
            prod *= num;
            sum += num;
        }
        return (n % (prod + sum) == 0);
    }
};
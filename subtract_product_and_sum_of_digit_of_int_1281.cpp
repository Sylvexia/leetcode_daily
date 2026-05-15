// 1281. Subtract the Product and Sum of Digits of an Integer

#include <bits/stdc++.h>
#include <string>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
public:
    int subtractProductAndSum(int n)
    {
        string str = to_string(n);
        int prod = 1;
        int sum = 0;
        for (char c : str) {
            int num = c - '0';
            prod *= num;
            sum += num;
        }
        return prod - sum;
    }
};
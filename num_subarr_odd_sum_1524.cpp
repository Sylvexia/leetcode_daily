// 1524. Number of Sub-arrays With Odd Sum

#include <bits/stdc++.h>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
public:
    int numOfSubarrays(vector<int> &arr)
    {
        int mod = 1e9 + 7;
        int res = 0, sum = 0;
        int numOdd = 0, numEven = 1;

        for (auto n : arr) {
            sum += n;
            if (sum % 2 == 0) {
                res += numOdd;
                numEven++;
            } else {
                res += numEven;
                numOdd++;
            }
            res %= mod;
        }
        return res;
    }
};
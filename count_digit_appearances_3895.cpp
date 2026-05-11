// 3895. Count Digit Appearances

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
    int countDigitOccurrences(vector<int> &nums, int digit)
    {
        int res = 0;
        for (int n : nums) {
            string str = to_string(n);
            for (char ch : str) {
                res += (ch - '0' == digit);
            }
        }
        return res;
    }
};
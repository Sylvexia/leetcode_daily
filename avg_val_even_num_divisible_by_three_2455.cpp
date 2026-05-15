// 2455. Average Value of Even Numbers That Are Divisible by Three

#include <bits/stdc++.h>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
public:
    int averageValue(vector<int> &nums)
    {
        int sum = 0;
        int cnt = 0;
        for (int n : nums) {
            if (n % 3 == 0 and n % 2 == 0) {
                sum += n;
                cnt++;
            }
        }
        if (cnt == 0)
            return 0;
        return sum / cnt;
    }
};
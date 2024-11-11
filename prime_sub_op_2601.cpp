// 2601. Prime Subtraction Operation

#include <bits/stdc++.h>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
public:
    bool primeSubOperation(vector<int> &nums)
    {
        bitset<1001> bset;
        for (int i = 0; i < 1001; i++)
            bset[i] = 1;
        bset[0] = 0;
        bset[1] = 0;
        for (int i = 2; i < 33; i++) {
            if (bset[i]) {
                for (int j = i * i; j < 1000; j += i)
                    bset[j] = 0;
            }
        }

        int cur = 1;
        int i = 0;
        int n = nums.size();
        while (i < n) {
            int target = nums[i] - cur;
            if (target < 0)
                return false;
            if (bset[target] or target == 0)
                i++;
            cur++;
        }
        return true;
    }
};
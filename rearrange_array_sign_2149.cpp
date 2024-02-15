// 2149. Rearrange Array Elements by Sign

#include <bits/stdc++.h>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
public:
    vector<int> rearrangeArray(vector<int> &nums)
    {
        vector<int> positive, negative, res;
        for (int n : nums) {
            if (n > 0)
                positive.push_back(n);
            else if (n < 0)
                negative.push_back(n);
        }

        for (int i = 0; i < nums.size() / 2; i++) {
            res.push_back(positive[i]);
            res.push_back(negative[i]);
        }
        return res;
    }
};
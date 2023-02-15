// 989. Add to Array-Form of Integer

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<int> addToArrayForm(vector<int> &num, int k)
    {
        vector<int> res{};

        int p = num.size() - 1, carry = 0, cur = 0;

        while (carry > 0 || k > 0 || p >= 0)
        {
            cur = k % 10 + carry;
            if (p >= 0)
                cur += num[p];
            res.push_back(cur % 10);
            carry = cur / 10;
            k /= 10;

            p--;
        }

        reverse(res.begin(), res.end());
        return res;
    }
};
// 869. Reordered Power of 2

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    bool reorderedPowerOf2(int n)
    {
        string n_str = sorted_num(n);
        for (int i = 0; i < 32; i++)
        {
            if (n_str == sorted_num(1 << i))
                return true;
        }
        return false;
    }

    inline string sorted_num(int n)
    {
        string res = to_string(n);
        sort(res.begin(), res.end());
        return res;
    }
};
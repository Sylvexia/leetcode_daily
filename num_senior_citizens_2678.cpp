// 2678. Number of Senior Citizens

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int countSeniors(vector<string> &details)
    {
        int res = 0;
        for (auto &d : details)
        {
            if ((d[11] - '0') * 10 + (d[12] - '0') > 60)
                res++;
        }
        return res;
    }
};
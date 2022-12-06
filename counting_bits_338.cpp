// 338. Counting Bits

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<int> countBits(int n)
    {
        int start = 0;
        int goal = n + 1;
        vector<int> res;
        while (start != goal)
        {
            int num = start;
            int count = 0;
            while (num)
            {
                num &= (num - 1);
                count++;
            }
            res.push_back(count);
            start++;
        }
        return res;
    }
};

class Solution2
{
public:
    vector<int> countBits(int n)
    {
        vector<int> res(n + 1, 0);
        res[0] = 0;
        for (int i = 1; i <= n; ++i)
            res[i] = res[i >> 1] + (i & 1);
        return res;
    }
};
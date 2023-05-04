// 495. Teemo Attacking

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int findPoisonedDuration(vector<int> &ts, int d)
    {
        d--;
        int start = ts[0], end = start + d, res = 0;
        for (int i = 0; i < ts.size(); i++)
        {
            if (i + 1 < ts.size() and end >= ts[i + 1])
                end = ts[i + 1] + d;
            else
            {
                res += (end - start) + 1;
                if (i + 1 == ts.size())
                    return res;
                end = ts[i + 1] + d;
                start = ts[i + 1];
            }
        }
        return res;
    }
};

class Solution
{
public:
    int findPoisonedDuration(vector<int> &ts, int d)
    {
        int start = ts[0], end = start + d, res = 0;
        for (int i = 1; i < ts.size(); i++)
        {
            if (ts[i] > end)
            {
                res += end - start;
                start = ts[i];
            }
            end = ts[i] + d;
        }
        res += end - start;
        return res;
    }
};

class Solution
{
public:
    int findPoisonedDuration(vector<int> &ts, int d)
    {
        int res = 0;
        for (int i = 1; i < ts.size(); i++)
        {
            int diff = ts[i] - ts[i - 1];
            if (diff >= d)
                res += d;
            else
                res += diff;
        }
        res += d;
        return res;
    }
};
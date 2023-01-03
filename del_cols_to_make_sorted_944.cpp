// 944. Delete Columns to Make Sorted

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int minDeletionSize(vector<string> &strs)
    {
        int m = strs.size(), n = strs[0].size();
        int res{};

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m - 1; j++)
            {
                if (strs[j][i] > strs[j+1][i])
                {
                    res++;
                    break;
                }
            }
        }

        return res;
    }
};
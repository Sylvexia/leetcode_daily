// 2643. Row With Maximum Ones

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>> &mat)
    {
        vector<int> ret = {0, 0};
        for (int i = 0; i < mat.size(); i++)
        {
            int cnt = 0;
            for (int j = 0; j < mat[0].size(); j++)
            {
                if (mat[i][j] == 1)
                    cnt++;
            }
            if (cnt > ret[1])
                ret = {i, cnt};
        }
        return ret;
    }
};
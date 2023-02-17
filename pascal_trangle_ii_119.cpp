// 119. Pascal's Triangle II

#include <bits/stdc++.h>

using namespace std;

class Solution
{

public:
    vector<int> getRow(int rowIndex)
    {
        vector<int> res(rowIndex + 1, 1);

        long temp = 1;
        for (int i = 1, up = rowIndex, down = 1;
             i <= rowIndex / 2; i++, up--, down++)
        {
            temp = temp * up / down;
            res[i] = temp;
            res[rowIndex - i] = temp;
        }

        return res;
    }
};
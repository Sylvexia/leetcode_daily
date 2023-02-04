// 6. Zigzag Conversion

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    string convert(string s, int numRows)
    {
        if (numRows <= 1)
            return s;
            
        vector<string> data(numRows, "");

        for (int i = 0, row = 0, step = 1; i < s.size(); i++)
        {
            data[row] += s[i];

            if (row == 0)
                step = 1;
            else if (row == numRows - 1)
                step = -1;

            row += step;
        }

        string ret;
        for (auto d : data)
            ret += d;

        return ret;
    }
};
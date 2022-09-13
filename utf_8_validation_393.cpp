#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    bool validUtf8(vector<int> &data)
    {
        int remain = 0;

        for (int i = 0; i < data.size(); i++)
        {
            if (remain == 0)
            {
                if (data[i] >> 5 == 0b110)
                    remain = 1;
                else if (data[i] >> 4 == 0b1110)
                    remain = 2;
                else if (data[i] >> 3 == 0b11110)
                    remain = 3;
                else if (data[i] >> 7 != 0)
                    return false;
            }
            else
            {
                if (data[i] >> 6 != 0b10)
                    return false;
                else
                    remain--;
            }
        }

        return remain == 0;
    }
};
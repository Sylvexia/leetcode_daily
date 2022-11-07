// 1323. Maximum 69 Number

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int maximum69Number(int num)
    {
        string str_num = to_string(num);
        for (char &ch : str_num)
        {
            if (ch == '6')
            {
                ch = '9';
                break;
            }
        }
        return stoi(str_num);
    }
};
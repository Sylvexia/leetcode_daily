// 2683. Neighboring Bitwise XOR

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    bool doesValidArrayExist(vector<int> &d)
    {
        int n = d.size();
        bool temp = false;
        for (int i = 0; i < n; i++)
        {
            if (d[i] == 1)
                temp = !temp;
        }
        return temp == false;
    }
};

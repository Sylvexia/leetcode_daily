// 1996. The Number of Weak Characters in the Game

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    static bool comp(vector<int> &a, vector<int> &b)
    {
        if (a[0] == b[0])
        {
            return a[1] > b[1];
        }
        return a[0] < b[0];
    }

    int numberOfWeakCharacters(vector<vector<int>> &properties)
    {
        sort(properties.begin(), properties.end(), comp);
        int mtn = INT_MIN;
        int res{};

        for (int i = properties.size() - 1; i >= 0; i--)
        {
            if (properties[i][1] < mtn)
                res++;
            mtn = max(mtn, properties[i][1]);
        }

        return res;
    }
};
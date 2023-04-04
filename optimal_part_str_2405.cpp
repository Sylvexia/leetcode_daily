// 2405. Optimal Partition of String

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int partitionString(string s)
    {
        int res = 0, pre_i = 0;
        unordered_map<char, int> u_map;

        for (int i = 0; i < s.size(); i++)
        {
            if (u_map[s[i]] >= pre_i)
            {
                pre_i = i + 1;
                res++;
            }
            u_map[s[i]] = i + 1;
        }
        return res;
    }
};

class Solution
{
public:
    int partitionString(string s)
    {
        int res = 0, pre_i = 0;
        int arr[26];
        memset(arr, 0, sizeof(arr));

        for (int i = 0; i < s.size(); i++)
        {
            if (arr[s[i] - 'a'] >= pre_i)
            {
                pre_i = i + 1;
                res++;
            }
            arr[s[i] - 'a'] = i + 1;
        }
        return res;
    }
};
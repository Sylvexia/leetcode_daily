// 763. Partition Labels

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<int> partitionLabels(string s)
    {
        unordered_map<char, int> u_map;

        for (int i = 0; i < s.size(); i++)
            u_map[s[i]] = i;

        vector<int> res;
        int prev = -1;
        int max_i = 0;

        for (int i = 0; i < s.size(); i++)
        {
            max_i = max(max_i, u_map[s[i]]);
            if (max_i == i)
            {
                res.push_back(max_i - prev);
                prev = max_i;
            }
        }
        return res;
    }
};

class Solution
{
public:
    vector<int> partitionLabels(string s)
    {
        int index_arr[26];

        memset(index_arr, 0, 26);

        for (int i = 0; i < s.size(); i++)
            index_arr[s[i] - 'a'] = i;

        vector<int> res;
        int prev = -1;
        int max_i = 0;

        for (int i = 0; i < s.size(); i++)
        {
            max_i = max(max_i, index_arr[s[i] - 'a']);
            if (max_i == i)
            {
                res.push_back(max_i - prev);
                prev = max_i;
            }
        }
        return res;
    }
};
// 451. Sort Characters By Frequency

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    string frequencySort(string s)
    {
        unordered_map<char, int> mp{};

        for (auto ch : s)
            mp[ch]++;

        vector<pair<int, char>> arr;
        for (auto &[c, freq] : mp)
            arr.push_back({freq, c});

        sort(arr.begin(), arr.end(), [](pair<int, char> &a, pair<int, char> &b)
             { return a.first > b.first; });

        string ans;
        for (auto& [freq,c]: arr)
            ans.append(freq,c);

        return ans;
    }
};
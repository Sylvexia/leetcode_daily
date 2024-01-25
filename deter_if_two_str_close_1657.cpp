// 1657. Determine if Two Strings Are Close

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    bool closeStrings(string word1, string word2)
    {
        ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
        unordered_map<char, int> count1, count2;
        for (char ch : word1)
            count1[ch]++;
        for (char ch : word2)
            count2[ch]++;

        if (count1.size() != count2.size())
            return false;

        vector<int> key1, key2, value1, value2;
        for (auto [key, value] : count1) {
            key1.push_back(key);
            value1.push_back(value);
        }
        for (auto [key, value] : count2) {
            key2.push_back(key);
            value2.push_back(value);
        }

        sort(key1.begin(), key1.end());
        sort(key2.begin(), key2.end());
        sort(value1.begin(), value1.end());
        sort(value2.begin(), value2.end());

        for (int i = 0; i < value1.size(); i++) {
            if (key1[i] != key2[i] or value1[i] != value2[i])
                return false;
        }
        return true;
    }
};

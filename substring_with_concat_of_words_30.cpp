// 30. Substring with Concatenation of All Words
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<int> findSubstring(string s, vector<string> &words)
    {
        int n = s.length();
        int num = words.size();
        unordered_map<string, int> counts;
        vector<int> indexes;

        if (n == 0 || num == 0)
            return indexes;

        int len = words[0].size();

        for (string word : words)
            counts[word]++;

        for (int i = 0; i < n - num * len + 1; i++)
        {
            unordered_map<string, int> seen;
            int j = 0;
            for (; j < num; j++)
            {
                string word = s.substr(i + j * len, len);
                if (counts.find(word) != counts.end())
                {
                    seen[word]++;

                    if (seen[word] > counts[word])
                        break;
                }
                else
                    break;
            }
            if (j == num)
                indexes.push_back(i);
        }
        return indexes;
    }
};
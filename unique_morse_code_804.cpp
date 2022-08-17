// 804. Unique Morse Code Words

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int uniqueMorseRepresentations(vector<string> &words)
    {
        array<string, 26> alphabet = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."};
        unordered_map<string, bool> count;

        for (int i = 0; i < words.size(); i++)
        {
            string str;
            for (int j = 0; j < words[i].size(); j++)
                str += alphabet[words[i][j] - 'a'];
            count[str] = true;
        }

        return count.size();
    }
};
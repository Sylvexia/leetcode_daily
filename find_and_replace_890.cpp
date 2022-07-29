// 890. Find and Replace Pattern

#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    vector<string> findAndReplacePattern(vector<string> &words, string pattern)
    {
        string match = patternize(pattern);
        vector<string> result;
        for (auto word : words)
        {
            if (match == patternize(word))
                result.push_back(word);
        }
        return result;
    }

    string patternize(string word)
    {
        unordered_map<char, char> map;
        char c = 'a';

        for (auto ch : word)
        {
            if (!map.count(ch))
                map[ch] = c++;
        }

        for (auto &ch : word)
            ch = map[ch];

        return word;
    }
};
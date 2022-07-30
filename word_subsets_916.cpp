// 916. Word Subsets
#include <vector>
#include <string>
#include <array>
#include <algorithm>

using namespace std;

class Solution
{
public:
    vector<string> wordSubsets(vector<string> &words1, vector<string> &words2)
    {
        vector<string> result;
        array<int, 26> count = {0};
        array<int, 26> tmp = {0};

        for (auto word : words2)
        {
            tmp = counter(word);
            for (int i = 0; i < 26; i++)
            {
                count[i] = max(count[i], tmp[i]);
            }
        }
        for (auto word : words1)
        {
            int i = 0;
            tmp = counter(word);
            for (i = 0; i < 26; ++i)
            {
                if (tmp[i] < count[i])
                    break;
            }
            if (i == 26)
                result.push_back(word);
        }

        return result;
    }

    array<int, 26> counter(string &word)
    {
        array<int, 26> count = {0};
        for (char c : word)
            count[c - 'a']++;
        return count;
    }
};
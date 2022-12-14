#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        if (s.size() != t.size())
            return false;

        int counter[26] = {0};

        for (int i = 0; i < s.size(); i++)
            counter[s[i] - 'a']++;

        for (int i = 0; i < t.size(); i++)
            counter[t[i] - 'a']--;

        for (int i = 0; i < 26; i++)
        {
            if (counter[i] != 0)
                return false;
        }
        return true;
    }
};
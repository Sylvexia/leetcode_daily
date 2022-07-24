// 792. Number of Matching Subsequences

#include <vector>
#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution
{
public:
    int numMatchingSubseq(string s, vector<string> &words)
    {
        vector<vector<int>> charMap(26);
        int n = s.length();
        int ans = words.size();

        for (int i = 0; i < n; i++)
        {
            charMap[s[i] - 'a'].push_back(i);
        }

        // string s:    f a e d b c
        // charMap:
        // index:       6 1 5 4 2 3
        // value:       1 2 3 4 5 6

        for (auto &word : words)
        {
            int last = -1;

            for (char c : word) // iterate though a word 
            {
                auto &alphabet = charMap[c - 'a'];
                auto it = upper_bound(alphabet.begin(), alphabet.end(), last);

                if(it == alphabet.end()) //if not found
                {
                    ans--;
                    break;
                }
                else
                {
                    last = *it;
                }
            }
        }

        return ans;
    }
};

int main(int argc, char** argv)
{
    Solution solution;

    string s="abcde";
    vector<string> words={"a","bb","acd","ace"};

    cout << solution.numMatchingSubseq(s,words);
    return 0;
}

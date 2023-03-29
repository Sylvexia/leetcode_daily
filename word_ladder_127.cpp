// 127. Word Ladder

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int ladderLength(string beginWord, string endWord, vector<string> &wordList)
    {
        unordered_set<string> u_set(wordList.begin(), wordList.end());

        queue<string> q;
        q.push(beginWord);

        int res = 1;

        while (!q.empty())
        {
            int count = q.size();

            for (int i = 0; i < count; i++)
            {
                string word = q.front();
                q.pop();

                if (word == endWord)
                    return res;

                u_set.erase(word);

                for (int j = 0; j < word.size(); j++)
                {
                    char temp_ch = word[j];
                    for (int k = 'a'; k <= 'z'; k++)
                    {
                        word[j] = k;
                        if (u_set.find(word) != u_set.end())
                        {
                            q.push(word);
                            u_set.erase(word);
                        }
                        word[j] = temp_ch;
                    }
                }
            }

            res++;
        }

        return 0;
    }
};
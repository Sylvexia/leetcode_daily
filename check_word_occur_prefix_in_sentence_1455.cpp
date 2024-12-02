// 1455. Check If a Word Occurs As a Prefix of Any Word in a Sentence

#include <bits/stdc++.h>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
public:
    int isPrefixOfWord(string sentence, string searchWord)
    {
        istringstream iss(sentence);
        string word;
        vector<string> words;
        while (iss >> word)
            words.push_back(word);

        for (int i = 0; i < words.size(); i++) {
            int j = 0;
            string curWord = words[i];
            while (j < searchWord.size() and j < curWord.size() and
                   curWord[j] == searchWord[j])
                j++;
            if (j == searchWord.size())
                return i + 1;
        }
        return -1;
    }
};
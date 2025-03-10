// 3306. Count of Substrings Containing Every Vowel and K Consonants II

#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

class Solution
{
    bool isVowel(char ch)
    {
        return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
    }

public:
    long long countOfSubstrings(string word, int k)
    {
        int n = word.size();
        unordered_map<char, int> vowels;

        vector<int> nextCons(n);
        int lastCons = n;
        for (int i = n - 1; i >= 0; i--) {
            nextCons[i] = lastCons;
            if (!isVowel(word[i]))
                lastCons = i;
        }

        int l = 0;
        int numCons = 0;
        long long res = 0;
        for (int r = 0; r < n; r++) {
            char newChar = word[r];
            if (isVowel(newChar))
                vowels[newChar]++;
            else
                numCons++;

            for (; numCons > k; l++) {
                char cur = word[l];
                if (isVowel(cur)) {
                    if (--vowels[cur] == 0)
                        vowels.erase(cur);
                } else {
                    numCons--;
                }
            }

            for (; l < n and vowels.size() == 5 and numCons == k; l++) {
                res += nextCons[r] - r;
                char cur = word[l];
                if (isVowel(cur)) {
                    if (--vowels[cur] == 0)
                        vowels.erase(cur);
                } else {
                    numCons--;
                }
            }
        }
        return res;
    }
};
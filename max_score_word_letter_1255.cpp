// 1255. Maximum Score Words Formed by Letters

#include <bits/stdc++.h>
#include <cstdlib>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
    int dfs(int idx,
            vector<string> &words,
            array<int, 26> &count,
            vector<int> &score)
    {
        if (idx >= words.size())
            return 0;

        int skip = dfs(idx + 1, words, count, score);
        int take = 0;

        bool sucess = true;
        array<int, 26> count_copy = count;

        for (char ch : words[idx]) {
            if (--count_copy[ch - 'a'] < 0)
                sucess = false;
            take += score[ch - 'a'];
        }

        return max(
            skip, sucess ? (take + dfs(idx + 1, words, count_copy, score)) : 0);
    }

public:
    int maxScoreWords(vector<string> &words,
                      vector<char> &letters,
                      vector<int> &score)
    {
        array<int, 26> cnt;
        for (int &n : cnt)
            n = 0;
        
        for (char ch : letters)
            cnt[ch - 'a']++;

        return dfs(0, words, cnt, score);
    }
};
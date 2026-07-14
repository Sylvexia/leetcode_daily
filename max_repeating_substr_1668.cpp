// 1668. Maximum Repeating Substring

#include <iostream>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
    bool startEq(const int start, string &sequence, string &word)
    {
        for (int i = 0; i < word.size(); i++)
            if (sequence[start + i] != word[i])
                return false;
        return true;
    }

public:
    int maxRepeating(string sequence, string word)
    {
        int res = 0;
        const int n = sequence.size();
        const int m = word.size();

        for (int i = 0; i < n - m + 1; i++) {
            int cur = 0;
            int j = i;
            while (startEq(j, sequence, word)) {
                j += m;
                cur++;
            }
            res = max(res, cur);
        }
        return res;
    }
};
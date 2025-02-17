// 1079. Letter Tile Possibilities

#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
    int dfs(unordered_map<char, int> &freq)
    {
        int res = 0;
        for (auto &[ch, count] : freq) {
            if (count == 0)
                continue;

            res++;
            count--;
            res += dfs(freq);
            count++;
        }
        return res;
    }

public:
    int numTilePossibilities(string tiles)
    {
        unordered_map<char, int> freq;
        for (char ch : tiles) {
            freq[ch]++;
        }
        return dfs(freq);
    }
};
// 2278. Percentage of Letter in String

#include <bits/stdc++.h>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
public:
    int percentageLetter(string s, char letter)
    {
        int n = s.size();
        int cnt = 0;
        for (char c : s)
            cnt += (c == letter);
        return cnt * 100 / n;
    }
};
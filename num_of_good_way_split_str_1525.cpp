// 1525. Number of Good Ways to Split a String

#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
public:
    int numSplits(string s)
    {
        int n = s.size();
        int res = 0;
        unordered_map<char, int> left, right;

        for (char c : s)
            right[c]++;

        for (int i = 0; i < n - 1; i++) {
            char ch = s[i];
            left[ch]++;
            right[ch]--;
            if (right[ch] == 0)
                right.erase(ch);
            res += left.size() == right.size();
        }
        return res;
    }
};
// 3163. String Compression III

#include <bits/stdc++.h>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
public:
    string compressedString(string word)
    {
        string res;
        int i = 0;
        int n = word.size();
        while (i < n) {
            int count = 0;
            char cur = word[i];
            while (i < n and count < 9 and word[i] == cur) {
                i++;
                count++;
            }
            res += to_string(count) + cur;
        }
        return res;
    }
};
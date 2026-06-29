// 1967. Number of Strings That Appear as Substrings in Word

#include <iostream>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
public:
    int numOfStrings(vector<string> &patterns, string word)
    {
        int res = 0;
        for (string &str : patterns) {
            res += word.find(str) != string::npos;
        }
        return res;
    }
};
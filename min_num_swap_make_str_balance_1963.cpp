// 1963. Minimum Number of Swaps to Make the String Balanced

#include <bits/stdc++.h>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
public:
    int minSwaps(string s)
    {
        int mismatch = 0;
        stack<char> stk;
        for (auto ch : s) {
            if (ch == '[')
                stk.push(ch);
            else {
                if (!stk.empty())
                    stk.pop();
                else
                    mismatch++;
            }
        }
        return (mismatch + 1) / 2;
    }
};
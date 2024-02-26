// 344. Reverse String

#include <bits/stdc++.h>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
public:
    void reverseString(vector<char> &s)
    {
        int n = s.size();
        for (int i = 0; i < n / 2; i++)
            swap(s[i], s[n - i - 1]);
        return;
    }
};
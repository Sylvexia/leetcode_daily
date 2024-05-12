// 168. Excel Sheet Column Title

#include <bits/stdc++.h>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
public:
    string convertToTitle(int n)
    {
        string res;

        while (n > 0) {
            n--;
            int mod = n % 26;
            n /= 26;
            res.push_back(mod + 'A');
        }

        reverse(res.begin(), res.end());
        return res;
    }
};
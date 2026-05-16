// 1374. Generate a String With Characters That Have Odd Counts

#include <bits/stdc++.h>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
public:
    string generateTheString(int n)
    {
        string res;
        if (n & 1) {
            for (int i = 0; i < n; i++)
            res.push_back('a');
        } else {
            for (int i = 0; i < n - 1; i++)
                res.push_back('a');
            res.push_back('b');
        }
        return res;
    }
};
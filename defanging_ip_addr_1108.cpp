// 1108. Defanging an IP Address

#include <bits/stdc++.h>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
public:
    string defangIPaddr(string address)
    {
        string res;
        for (auto ch : address) {
            if (ch == '.')
                res.append("[.]");
            else
                res.push_back(ch);
        }
        return res;
    }
};
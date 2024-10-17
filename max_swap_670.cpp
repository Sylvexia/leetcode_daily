// 670. Maximum Swap

#include <bits/stdc++.h>
#include <string>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
public:
    int maximumSwap(int num)
    {
        string str = to_string(num);
        string res = str;

        for (int i = 0; i < str.size(); i++) {
            for (int j = i + 1; j < str.size(); j++) {
                swap(str[i], str[j]);
                res = max(res, str);
                swap(str[i], str[j]);
            }
        }

        return stoi(res);
    }
};
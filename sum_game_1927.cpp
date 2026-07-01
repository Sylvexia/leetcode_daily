// 1927. Sum Game

#include <iostream>

using namespace std;

static int speedup = []() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();

class Solution
{
public:
    bool sumGame(string num)
    {
        double a = 0;
        int n = num.size();
        for (int i = 0; i < n / 2; i++)
            a += num[i] == '?' ? 4.5 : num[i] - '0';
        for (int i = n / 2; i < n; i++)
            a -= num[i] == '?' ? 4.5 : num[i] - '0';
        return a != 0;
    }
};